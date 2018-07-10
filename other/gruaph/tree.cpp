#include <iostream>
#include <vector>

using std::cin;
using std::cout;

const int MAXV = 10000;

vector<int> graph[MAXV];

int main()
{
	int n,x,y;

	cin>>n;

	for(int i = 0;i < n;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	return 0;
}
