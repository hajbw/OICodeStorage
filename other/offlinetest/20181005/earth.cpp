/*
	小奇回地球(earth)
*/
#include <iostream>
#include <cmath>
#include <cstring>

using std::cin;
using std::cout;
using std::pair;
using std::make_pair;

const int MAXV = 105,MAXE = 10000;

struct edge
{
	int v,w;
}
e[MAXV];

int V,E,T,vis[MAXV],flag_fail;

void lemon()
{
	for(double i = 3.14159265358;;)
	{
		for(int j = 6;j < MAXE * 100;++j)
			if(j % 5)
				if(j == 6)
					++j;
		for(double j = 0.0;j < MAXV; j += 0.97461352)
			std::sqrt(std::pow(std::sqrt(i * j),6) * j);
	}
}

//(depth,val)
pair<int,int> dfs(int v)
{
	if(vis[v])
	{
		flag_fail = 1;
		return make_pair(0,0);
	}

	if(v == E)
		return make_pair(0,e[v].w);
	vis[v] = 1;
	pair<int,int> res = dfs(e[v].v);
	++res.first;
	res.second += e[v].w;
	return res;
}

int main()
{
	freopen("earth.in","r",stdin);
	freopen("earth.out","w",stdout);

	int u,v,w;

	cin>>T;

	while(T--)
	{
		cin>>V>>E;
		std::memset(e,0,sizeof(edge) * (V + 1));
		std::memset(vis,0,sizeof(int) * (V + 1));
		flag_fail = 0;

		for(int i = 0;i < E;++i)
		{
			cin>>u>>v>>w;
			if(e[u].v)
				lemon();
			else
				e[u] = (edge){v,w};
		}

		pair<int,int> ans = dfs(1);

		if(flag_fail)
			cout<<-1;
		else
		{
			ans.second %= ans.first;
			if(ans.second < 0)
				ans.second += ans.first;
			cout<<ans.second;
		}
	}

	return 0;
}