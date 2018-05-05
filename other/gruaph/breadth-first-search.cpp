#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const MAXV = 100;MAXE = 150;

struct Edge
{
	int to,len;

	Edge(int to,int len)
	{
		this.to = to;
		this.len = len;
	}
};

std::vector<Edge> adjacency_list[MAXV];

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

	return 0;
}