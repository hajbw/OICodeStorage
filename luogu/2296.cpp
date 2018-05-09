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
std::vector<int>::iterator it;
int available[MAXV] = {-1},dist[MAXV],in_queue[MAXV] = {0};

void DFS(int i)
{
	if(available[i] != -1)
		return;
	available[i] = 1;
	for(it = rev_adj_list[i].begin();it != rev_adj_list[i].end();++it)
	{
		DFS(*it);
	}
}

int main()
{
	int m,n,a,b,i;
	
	memset(dist,63,sizeof(dist));

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
	
	//exclude unavailble points
	for(i = 0;i < n;++i)
		if(available[i] == -1)
			for (it = rev_adj_list[i].begin(); it != rev_adj_list[i].end(); ++it)
			{
				available[*it] = 0;
			}
	
	//SPFA
	std::queue<int> que;
	que.push(b);
	in_queue[b] = 1;
	dist[b] = 0;
	while(!que.empty())
	{
		i = que.front();
		que.pop();

		for (it = rev_adj_list[i].begin(); it != rev_adj_list[i].end(); ++it)
		{
			if(available[*it] == 1 && dist[*it] > dist[i] + 1)
			{
				dist[*it] = dist[i] + 1;
				if(!in_queue[*it])
				{
					que.push(*it);
					in_queue[*it] = 1;
				}
			}
		}

		in_queue[i] = 0;
	}
	
	
	cout<<dist[a];

	return 0;
}
