#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int tu[60][60];
struct node//邻接表中的元素
{ int v,len;
};
struct node2//优先队列中的元素
{int no,dis;};
bool operator<(node2 a,node2 b)
{ return a.dis>b.dis;//小值优先
}
priority_queue<node2> prio;//优先队列
vector<node> g[60];
int p;
long long dis[60];
int finished[60];
void init()
{  
    memset(tu,63,sizeof(tu));
	for(int i=0;i<60;i++) tu[i][i]=0;
   for(int i=0;i<60;i++) dis[i]=INT_MAX/2-1;
   memset(finished,0,sizeof(finished));
}
void datainput()
{ cin>>p;//边的数量
  char y,x;
  int  l,a,b;
  for(int i=0;i<p;i++) 
   { cin>>x>>y>>l;  //边的端点和长度
     a=int(x)>96?int(x)-71:int(x)-65;
	 b=int(y)>96?int(y)-71:int(y)-65;
    node t;
	if(l<tu[a][b])
    {	//邻接表存储图
	  tu[a][b]=l;tu[b][a]=l;
	  t.v=b;t.len=l;
	  g[a].push_back(t);
	  t.v=a;t.len=l;
	  g[b].push_back(t);
	 }
   }
}
void dj()//
{ 
  int start=25; dis[start]=0; 
  node2 t2;
  t2.no=start; t2.dis=0;
  prio.push(t2);  //结点编号与dis值的组合入队
  while( prio.size()>0 )
   { t2=prio.top();//从队列取出起点
      start=t2.no; prio.pop();
	  if(finished[start]) continue; //已完成点不要
      for(unsigned int i=0;i<g[start].size();i++)//修改与start可达点的dis值
     {  
	     int t=g[start][i].v, len=g[start][i].len;
	    if(dis[t]>dis[start]+len)
		{  dis[t]=dis[start]+len;
		    t2.no=t;t2.dis=dis[t]; 
			prio.push(t2);//结点编号与dis值的组合入队
		}
	 }
	 finished[start]=1;
   }
   long long min=INT_MAX,v;
     for(int i=0;i<25;i++)//找最小dis值的点
       if(dis[i]<min) {min=dis[i];v=i;}
	char c=(v+65);
	cout<<c<<" "<<min;
}
int main()
{  init();
   datainput();
  dj();
}
