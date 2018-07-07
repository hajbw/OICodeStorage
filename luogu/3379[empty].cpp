#include <iostream>
#include <vector>

/*
	P3379【模板】最近公共祖先（LCA）
*/

using std::cin;
using std::cout;
using std::vector;

const int MAXN = 500000,MAXM = 500000;

vector<int> graph[MAXN];
int M,N,S;

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
		;

	return 0;
}