#include <iostream>
#include <vector>

#define max(a,b) (a > b ? a : b)

using std::cin;
using std::cout;
using std::vector;

const int MAXV = 10005;

vector<int> graph[MAXV];

int root;

namespace diameter
{

namespace tree_dp
{

int max_len[MAXV];

void diameter_tree_dp_dfs(int v)
{
	for(vector<int>::iterator it = graph[v].begin();it != graph[v].end();++it)
	{
		diameter_tree_dp_dfs(*it);
		max_len[v] = max(max_len[v],max_len[*id] + 1);
	}
}

int get()
{
	return 0;
}

}//end tree dp

namespace find_longest
{

#ifndef _CSTDIO_
#include <cstdio>
#endif

int dist[MAXV];

int dfs_get_furthest(int v,int di)
/**
	get furthest from v

	arguments:
	v : point
	dist : current distance,initially 0(maybe any int also works)

	return:
	furthest point from v

*/
{
	int furthest = v;//current furthest point

	dist[v] = di;

	for(vector<int>::iterator it = graph[v].begin();it != graph[v].end();++it)
		if(dis[furthest] < dis[dfs_get_furthest(*it,di + 1)])
			furthest = *it;

	return furthest;
}
	
int get(int v)
{
	int u = dfs_get_furthest(v,0);
	v = dfs_get_furthest(u,0);
	return dis[v]
}

}

}//end diameter

//end get tree diameter

int main()
{
	std::ios::sync_with_stdio(false);

	int n,x,y;

	cin>>n>>root;

	for(int i = 0;i < n;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}



	return 0;
}
