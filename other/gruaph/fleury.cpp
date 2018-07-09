#include <iostream>
#include <vector>
#include <utility>

/*
	Fleury's algorithm
*/

using std::cin;
using std::cout;
using std::pair;

const int MAXV = 1001,MAXE = 5005;

vector<pair<int,bool>> graph[MAXV];
int V,E;

int fleury(int v)
{

}

int main()
{
	std::ios::sync_with_stdio(false);

	int x,y;

	cin>>V>>E;

	for(int i = 0;i < E;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	return 0;
}