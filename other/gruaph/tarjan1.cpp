#include <iostream>
#include <vector>
#include <stack>

/*
	get Strongly Connected Components
*/

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int
	MAXV = 100,MAXE = 200;

template<class T1,class T2>struct hpair
{
	T1 first;
	T2 second;
	hpair():first(),second(){}
	hpair(T1 &a,T2 &b):first(a),second(b){}
}


vector<int> graph[MAXV],c_graph[MAXV];
std::stack<int> st;
//  WTF      timestamp             in-degree
int low[MAXV],dfn[MAXV],stat[MAXV],id[MAXV];
int clock = 0;

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
	return 0;
}
