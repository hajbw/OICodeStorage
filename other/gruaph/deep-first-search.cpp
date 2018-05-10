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
int visited[MAXV] {0};

void fuckV(int i)
{
	cout<<"Vertice "<<i<<endl;
}

void fuckE(int from,Edge e)
{
	cout<<"Edge("<<e.len<<") "<<from<<" -> "<<e.to<<endl;
}

void dfs(int i)
{
	visited[i] = 1;
	for (std::vector<Edge>::iterator it = adjacency_list[i].begin(); it != adjacency_list[i].end(); ++it)
		if(!visited[*it.to])
		{
			fuckE(i,*it);
			fuckV(i);
			dfs(*it.to);
		}
}

int main()
{
	int m,n,a,b,c;
	
	cin>>m>>n;//V,E
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