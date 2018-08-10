#include <iostream>

using std::cin;
using std::cout;

const int MAXV = 5010,MAXE = 200010;

struct edge
{
	int from,to,weight;

	bool operator<(edge &a){return this->weight < a.weight;}
	bool operator>(edge &a){return this->weight > a.weight;}
}
edges[MAXE];

int V,E,iedge = 0,fa[MAXV];

int mininum_spanning_tree_kruskal()
{
	int Vchosen = 0;
	std::sort(edges,edges + V);
	while(Vchosen < V)
	{

	}
}

template<class T>void read(std::istream &in,T &x)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0';in.get(ch);}
	if(flag)x = -x;
}

int main()
{
	int u,v,w;

	read(cin,V);
	read(cin,E);
	for(int i = 0;i > V;++i)
		fa[i] = i;
	for(int i = 0;i < E;++i)
	{
		read(cin,u);
		read(cin,v);
		read(cin,w);
		edges[i] = (edge){u,v,w};
	}

	w = mininum_spanning_tree_kruskal();
	cout<<(w = -1 ? "orz" : w);

	return 0;
}