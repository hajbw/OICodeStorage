#include <iostream>
#include <vector>
#include <cstring>

#define max(a,b) (a > b ? a : b)

using std::cin;
using std::cout;
using std::vector;

const int MAXV = 10005;

vector<int> graph[MAXV];

int V,E;

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
		max_len[v] = max(max_len[v],max_len[*it] + 1);
	}
}

int get()
{
	return 0;
}

}//end tree dp

namespace find_longest
{

int dis[MAXV],vis[MAXV];

int dfs_get_furthest(int v,int di)
/**
	get furthest from v

	arguments:
	v : point
	di : current distance,initially 0(maybe any int also works)

	return:
	furthest point from v
*/
{
	int furthest = v;//current furthest point
	vis[v] = 1;
	dis[v] = di;

	for(vector<int>::iterator it = graph[v].begin();it != graph[v].end();++it)
		if(!vis[*it] && dis[furthest] < dis[dfs_get_furthest(*it,di + 1)])
			furthest = *it;

	return furthest;
}
	
int get()
{
	int v = 0,u = dfs_get_furthest(E >> 1,0);
	std::memset(dis,0,sizeof(dis));
	std::memset(vis,0,sizeof(vis));
	v = dfs_get_furthest(u,0);
	return dis[v];
}

}

}//end diameter

int main()
{
	std::ios::sync_with_stdio(false);

	int x,y;

	cin>>E;

	for(int i = 0;i < E;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout<<diameter::find_longest::get();

	return 0;
}
