#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
#define maxN 100001
using namespace std;
int n,m,cnt;
int edges=0;//边的数量
int cost[maxN];//各城市价格
int buy[maxN],sale[maxN];
vector<int> g[maxN],antig[maxN];
void spfa1()
{ deque<int> dq;
	int indq[maxN];
    memset(buy,63,sizeof(buy));//初值设很大
	buy[1]=cost[1];dq.push_back(1);indq[1]=1;//1入队列
	while( dq.size()>0 )
	{int s=dq.front(); dq.pop_front();indq[s]=0;//取队头点
	  for(int i=0;i<g[s].size();i++)
	  { int v=g[s][i];
		if(buy[s]<buy[v]||buy[v]>cost[v])
		{ buy[v]=min(buy[s],cost[v]);
		   if( indq[v]==0) { indq[v]=1; //被更新的点入队列
			                         dq.push_back(v);
			                       }
		}
	  }
	}
}
void spfa2()
{ deque<int> dq;
	int indq[maxN];
	memset(indq,0,sizeof(indq));
    memset(sale,0,sizeof(sale));//初值很小
	dq.push_back(n);indq[n]=1;sale[n]=cost[n];
	while( dq.size()>0 )
	{int s=dq.front(); dq.pop_front();indq[s]=0;//取队头点
	  for(int i=0;i<antig[s].size();i++)
	  { int v=antig[s][i];
		if( sale[s]>sale[v]|| sale[v]<cost[v] )
		{ sale[v]=max(sale[s],cost[v]);
		   if( indq[v]==0) { indq[v]=1; //被更新的点入队列
			                        dq.push_back(v);
			                       }
		}
	  }
	}
}
int main()
{
	freopen("trade9.in","r",stdin);
	cin>>n>>m; //城市数和道路数
	for(int i=1;i<=n;i++)
	{	cin>>cost[i]; //各城价格
	    buy[i]=cost[i];sale[i]=cost[i];
	}
  for(int i=1,x,y,z;i<=m;i++)
    {  cin>>x>>y>>z;
	    g[x].push_back(y);
		antig[y].push_back(x);
		if(z==2){ g[y].push_back(x);
			           antig[x].push_back(y);
		             }
    }
   spfa1();spfa2();
    int ans=0;
    for(int i=1;i<=n;i++)
		ans=max(sale[i]-buy[i],ans);
    printf("%d",ans);
	return 0;
}
