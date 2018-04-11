#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

/*
	P1529 回家 Bessie Come Home
*/

const int MAX_V = 30,MAX_E = 10000;

struct adjecency_list_node
{
	int v,length;
};

int diatance[MAX_V],parent[MAX_V];
bool isFinished[MAX_V] {false};
vector<adjecency_list_node> adjecency_list[MAX_V]

using namespace std;

//adajency list
int degree[MAX_V];

int main()
{
	int Ecount,length;
	char a,b;

	memset();
	
	//input

	cin>>Ecount;
	
	for(int i = 0;i < Ecount;++i)
	{
		cin>>a>>b>>length;

		a -= ( a > 92 ? 71 : 65 );
		b -= ( b > 92 ? 71 : 65 );

		adjecency_list[a].v = b;
		adjecency_list[a].length = length;
	}

	//calculate

	return 0;
}
