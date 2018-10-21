/*
	P1091 合唱队形
	brute-force search
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 105;

int arr[MAXN],N,vis[MAXN];

void dfs(int n,int cnt)
{
	if(n > N)
	{
		for(int i = 1;i <= N;++i)
		{
			if(vis[i])
				continue;

		}
	}

	dfs(n + 1)
	vis[n] = 1;
	dfs(n + 1);
	vis[n] = 0;
}

int main()
{
	cin>>N;
	for(int i = 1;i <= N;++i)
		cin>>arr[i];

	return 0;
}