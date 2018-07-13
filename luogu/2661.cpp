#include <iostream>

#ifndef min
#define min(a,b) (a < b ? a : b)
#endif

/*
	P2661 信息传递
*/

using std::cin;
using std::cout;

const int MAXN = 200000;

int
	N,timer,ans = 19260817,
	graph[MAXN],timestamp[MAXN],start[MAXN];

void dfs(int v,int s)
{		
	timestamp[v] = ++timer;
	start[v] = s;
	if(!timestamp[to[v]])
		dfs(to[v]);
	else if(s == start[to[v]])
		ans = min(ans,timestamp[v] - timestamp[to[v]]);
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin>>N;

	for(int i = 0;i < N;++i)
		cin>>to[i];

	for(int i = 0;i < N;++i)
		if(!timestamp[i])
			dfs(i,i);

	cout<<ans;

	return 0;
}