#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#define MAXN 210
#define MAXM 210
using namespace std;
struct EDGE
{ int to,cap,rev;
  //rev反边的存储位置
};
int n,m,flow=0;
int used[MAXM];
vector<EDGE> edge[MAXN];//图邻接表
void addedge(int from,int to,int cap)
{ //建图 起点 终点 容量
   int size1=edge[from-1].size(),size2=edge[to-1].size();
   EDGE temp;
   temp.to=to-1;temp.cap=cap;temp.rev=size2;
   edge[from-1].push_back(temp);
   temp.to=from-1;temp.cap=0;temp.rev=size1;
   edge[to-1].push_back(temp);
}
int dfs(int s,int t,int f)
{ //返回s到t的增加流，f是s点的可增量
  used[s]=1;
  if(s==t) 
       return f;
  for(int i=0;i<edge[s].size();i++)
       { if(used[edge[s][i].to]==0&&edge[s][i].cap>0)
		     {  int f2=f<edge[s][i].cap?f:edge[s][i].cap;
			    int f3=dfs(edge[s][i].to,t,f2);
				if(f3>0) 
				  {   edge[s][i].cap-=f3;
				       edge[edge[s][i].to][edge[s][i].rev].cap+=f3;
					   return f3;
				   }
			 } 
	   }
	return 0;
}
int max_flow(int s,int t)
{  
   int flow=0;
   int f;
   do{ memset(used,0,sizeof(used));
         f=dfs(s,t,INT_MAX);
         flow+=f;
		}
   while(f>0);
   return flow;

}

int main()
{  cin>>n>>m;
   int from,to,cap;
   for(int i=0;i<n;i++)
   { 
     cin>>from>>to>>cap;
	 addedge(from,to,cap);
   }
   cout<<max_flow(0,m-1);
}
