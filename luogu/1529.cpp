#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>

/*
	P1529 回家 Bessie Come Home
*/

const int MAX_V = 26,MAX_E = 10000;

struct adjecency_list_node
{
	int v,length;

	adjecency_list_node(int v,int length)
	{
		this.v = v;
		this.length = length;
	}
};

int distance[MAX_V],parent[MAX_V];
bool isFinished[MAX_V] {false};
vector<adjecency_list_node> adjecency_list[MAX_V]

using namespace std;

//adajency list
int degree[MAX_V];

int main()
{
	int Ecount,length,result_cowNo,result_length;
	char a,b;

	memset(distance,INT_MAX,MAX_V);
	
	//input
	cin>>Ecount;
	for(int i = 0;i < Ecount;++i)
	{
		cin>>a>>b>>length;

		a -= ( a > 92 ? 71 : 65 );
		b -= ( b > 92 ? 71 : 65 );

		adjecency_list[a].v = b;
		adjecency_list[a].length = length;
		adjecency_list[b].v = a;
		adjecency_list[b].length = length;
	}

	//calculate

	//output
	cout<<char(result_cowNo > 13 ? result_cowNo + 'A' :result_cowNo + 'a' )<<
	" "<<
	result_length;

	return 0;
}
