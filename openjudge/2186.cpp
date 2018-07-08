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
//  WTF      timestamp
int low[MAXV],dfn[MAXV],stat[MAXV];
int V,E,jzm_clock = 0;

//get Strongly Connected Components
void tarjan(int u)
{
	++stat[u];//ing:1
	++jzm_clock;
	dfn[u] = low[u] = jzm_clock;
	st.push(u);
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
	vector<int> ans;

	cin>>V>>E;

	for(int i = 0;i < E;++i)
	{
		cin>>x>>y;// x -> y
		graph[x].push_back(y);
	}

	tarjan(1);

	for(vector<int>::iterator it = ans.begin(); it != ans.end();++it)
		cout<<*it;

	return 0;
}