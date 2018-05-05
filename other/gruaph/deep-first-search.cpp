#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int MAXV = 100,MAXE = 100;

struct Edge
{
	int to,len;

	Edge(int to,int len)
	{
		this.to = to;
		this.len = len;
	}
};

vector<int> adjacency_list[MAXV];

void dfs()
{

}

int main()
{
	int n,a,b,c;
	
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		//format: from to lenth
		cin>>a>>b>>c;
		adjacency_list[a].push_back(new Edge(b,c));
	}

	cin>>n;
	dfs(n);

	return 0;
}