//草地排水
//正向逆向邻接表
#include<cstring>
#include<iostream>
#include<climits>

using namespace std;

int N,M;//边数，点数
struct EDGE
{
	int to,next;
};

EDGE e[202],antie[202];//正向逆向邻接表

int num=0;
int h[202],antih[202],g[202][202];//h[2]  anti[2]
int c[201][201],f[201][201];//容量和流量c[i][j]
int used[201];

void addedge(int from,int to,int cap)
{
	c[from][to]=cap;
	num++;
	e[num].to=to;
	e[num].next=h[from];
	h[from]=num;
	antie[num].to=from;
	antie[num].next=antih[to];
	antih[to]=num;
}
int dfs(int x,int det)//目前在x点，改进量是det
{
	int y,min1,t1;
	if(x==M) return det;
	used[x]=1;
	for(int i=h[x];i!=0;i=e[i].next)
	{
		y=e[i].to;
		if(used[y]==0&& f[x][y]<c[x][y])
		  {  min1=det<c[x][y]-f[x][y]?det:c[x][y]-f[x][y];
		      t1=dfs(y,min1);
			   if(t1==0)
			   continue;//x-->y 没可改进路
			   f[x][y]+=t1;
			   return t1;
		  }
	}
	for(int i=antih[x];i!=0;i=e[i].next)
	{
		y=antie[i].to;
	    if( used[y]==0&& f[y][x]>0)
		{ min1=det<f[y][x]?det:f[y][x];
		   t1=dfs(y,min1);
		   if(t1==0) continue;//  x<--y 没可改进路
		   f[x][y]-=t1;
		   return t1;
		}
	}
	return 0;//能执行到这里，说明找不到可改进路
}
int main()
{
	cin>>N>>M;
	memset(c,0,sizeof(g));
	for(int from,to,cap,i=1;i<=N;i++)
	{
		cin>>from>>to>>cap;
		if(from!=to)  c[from][to]+=cap;//邻接矩阵，记录容量
	}
	for(int i=1;i<=M;i++)
		for(int j=1;j<=M;j++)
			if(i!=j&&c[i][j]>0)
				addedge(i,j,c[i][j]);
	int flow=0,t;
	do
	{
		memset(used,0,sizeof(used));
		t=dfs(1,INT_MAX);
		flow+=t;
	}
	while(t>0);
	cout<<flow;
}
