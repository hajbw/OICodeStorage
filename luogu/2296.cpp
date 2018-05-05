#include <iostream>
#include <vector>

/*
	P2296 寻找道路	
*/

using std::cin;
using std::cout;
using std::endl;

const int MAXV = 10000,MAXE = 200000;

//unweighted graph
std::vector<int> adj_list[MAXV];
int m,n,a,b;

int main()
{
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		adj_list[a].push_back(b);
	}
}