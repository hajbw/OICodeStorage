#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int MAXV = 100,MAXE = 100;


void dfs()
{

}

int main()
{
	vector<int> adjacency_list[MAXV];
	int n,a,b,c;

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b>>c;
	}

	cin>>n;
	dfs(n);

	return 0;
}