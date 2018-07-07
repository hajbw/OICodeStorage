#include <iostream>
#include <vector>
#include <stack>
#include <utility>

#define min(a,b) (a < b ? a : b)

/*
	get Strongly Connected Components
*/

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int
	MAXV = 10000,MAXE = 50000,
	STAT_UNVISITED = 0,
	STAT_VISITING = 1,
	STAT_VISITED = 2;

vector<int> graph[MAXV],c_graph[MAXV],components_id;
vector<vector<int>> components;
std::stack<int> st;
//  WTF      timestamp             in-degree
int low[MAXV],dfn[MAXV],stat[MAXV],id[MAXV];
int V,E,clock = 0;

//get Strongly Connected Components
void tarjan(int u)
{
	++stat[u];//ing:1
	++clock;
	dfn[u] = low[u] = clock;
	stack.push(u);
	for(vector<int>::iterator it = graph[u].begin();it != graph[u].end();++it)
	{
		if(!dfn[*it])
		{
			tarjan(*it);
			low[u] = min(low[u],low[*it]);
		}
		else if(stat[*it] == 1)
		{
			low[u] = min(low[u],dfn[*it]);
		}
	}
	++stat[u];//ed:2
	if(dfn[u] == low[u])
	{
		vector<int> component;
		int v = st.top();
		st.pop();
		component.push_back(v);
		while(u != v)
		{
			v = st.top();
			st.pop();
			component.push_back(v);
		}
		components.push_back(component);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	int x,y;

	cin>>V>>E;

	for(int i = 0;i < E;++i)
	{
		cin>>x>>y;// x -> y
		++id[y];
	}

	tarjan(1);

	//sum up every component
	for(auto it = components.begin();it != components.end();++it)
	{
		int sum = 0;
		for(auto iit = (*it).begin();iit != (*it).end();++iit)
			sum += id[*iit];
		components_id.push_back(sum);
	}

	return 0;
}