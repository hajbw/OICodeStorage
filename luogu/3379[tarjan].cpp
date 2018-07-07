#include <iostream>
#include <vector>

/*
	P3379【模板】最近公共祖先（LCA）
	Tarjan version
*/

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int
	MAXN = 500000,MAXM = 500000,
	STAT_UNVISITED = 0,
	STAT_VISITING = 1,
	STAT_VISITED = 2;

vector<int> graph[MAXN];
int M,N,S;
int target_a[MAXN],target_b[MAXN],stat[MAXN];

void tarjan(int v)
{
	++stat[v];
	for(vector<int>::iterator it = graph[v].begin();it != graph[v].end();++it)
	{

	}
	++stat[v];
}

int main()
{
	std::ios::sync_with_stdio(false);

	int x,y;

	cin>>N>>M>>S;

	tree[1] = S;

	for(int i = 0;i < N - 1;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);		
	}

	for(int i = 0;i < M;++i)
		cin>>target_a>>target_b;

	for (int i = 0;i < M; ++i)
		cout<<ans[i]<<endl;

	return 0;
}