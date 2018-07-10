#include <iostream>
#include <vector>

#define max(a,b) (a > b ? a : b)

using std::cin;
using std::cout;
using std::vector;

const int MAXV = 10005;

vector<int> graph[MAXV];

//get tree diameter

//tree dp

int max_len[MAXV];

void diameter_tree_dp_dfs(int v)
{
	for(vector<int>::iterator it = graph[v].begin();it != graph[v].end();++it)
	{
		diameter_tree_dp_dfs(*it);
		max_len[v] = max(max_len[v],max_len[*id] + 1);
	}
}

//end tree dp

//end get tree diameter

int main()
{
	std::ios::sync_with_stdio(false);

	int n,x,y,root = 0;

	cin>>n>>root;

	for(int i = 0;i < n;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}



	return 0;
}
