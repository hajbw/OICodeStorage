#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

/*
	P2296 寻找道路	
*/

using std::cin;
using std::cout;
using std::endl;

const int MAXV = 10000,MAXE = 200000;

//unweighted graph!
//std::vector<int> adj_list[MAXV];
std::vector<int> rev_adj_list[MAXV];
int available[MAXV] = {-1},dist[MAXV];

void DFS(int i)
{
	if(available[i] = -1)
		return;
	available[i] = 1;
	for(std::vector<int>::iterator it = rev_adj_list[i].begin();it != rev_adj_list[i].end();++it)
	{
		DFS(*it);
	}
}

void DFS_exclude(int i)
{

}

int main()
{
	int m,n,a,b,i,result = 19260817;
	
	memset(dist,19260817,sizeof(dist));

	//Vertice,Edge
	cin>>n>>m;
	for (i = 0; i < m; ++i)
	{
		cin>>a>>b;
		//adj_list[a].push_back(b);
		rev_adj_list[b].push_back(a);
	}
	cin>>a>>b;//s,t

	//DFS rev-graph
	DFS(b);
	
	for(i = 0;i < n;++i)
		if(!available[i]);
			
	
	//SPFA
	std::queue<int> que;
	que.push(a);
	
	
	cout<<result;
	
	return 0;
}