#include <cstdio>
#include <vector>

#ifndef max
#define max(a,b) (a > b ? a : b)
#endif

#ifndef min
#define min(a,b) (a < b ? a : b)
#endif

using std::scanf;
using std::printf;

/**
	P1262 间谍网络
*/

using std::vector;

const int MAXV = 3005,MAXE = 12000;

vector<int> graph[MAXV];
int
	cost[MAXV],//cost to buy.unable if 0.
	fa[MAXV],//father(v),union_find set.
	n,p,r;//... ntr???

int
	jzm_clock,//clock
	dfn[MAXV],//timestamp_discover_time
	low[MAXV];//WTF
void tarjan(int v)
{

}

int main()
{
	int x,y;

	scanf("%d",&n);
	scanf("%d",&p);
	for(int i = 0;i < p;++i)
	{
		scanf("%d %d",&x,&y);
		cost[x] = y;
	}
	scanf("%d",&r);
	for(int i = 0;i < r;++i)
	{
		scanf("%d %d",&x,&y);
		graph[x].push_back(y);
	}

	return 0;
}
