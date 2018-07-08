#include <cstdio>
//sorry,iostream

/*
	P3379【模板】最近公共祖先（LCA）
	Tarjan version
*/

using std::printf;
using std::scanf;

const int MAXN = 500005,MAXM = 500005,DEBUG = 1;

typedef int iEdge;
typedef int iVert;

struct Edge
{
	int to,next;
}
edges[MAXN*2],querys[MAXM*2];// *2 scale for 2 directions

int
	cnt_edges,cnt_query,
	head_graph[MAXN],head_query[MAXM],
	M,N,S,
	fa[MAXN],visited[MAXN],ans[MAXM];

int find(int v)
{
	if(v != fa[v])
		fa[v] = find(fa[v]);
	return fa[v];
}

void tarjan(int v)
{
	fa[v] = v;
	visited[v] = 1;
	for(iEdge i = head_graph[v];i != 0;i = edges[i].next)
	{
		if(!visited[edges[i].to])
		{
			tarjan(edges[i].to);
			fa[edges[i].to] = v;
		}
	}

	for(iEdge i = head_query[v];i != 0;i = edges[i].next)
		if(visited[querys[i].to])
		{
			ans[i >> 1] = find(querys[i].to);
			printf("%d \n",ans[i >> 1]);
		}

	if(DEBUG)
		printf("v: %d vi: %d fa: %d \n",v,visited[v],fa[v]);
}

void addedge(int u,int v)
{
	edges[cnt_edges].to = v;
	edges[cnt_edges].next = head_graph[u];
	head_graph[u] = cnt_edges;
	if(DEBUG)
		printf("addedge %d -> %d ,cnt: %d\n",u,v,cnt_edges);
	++cnt_edges;
}

void addquery(int u,int v)
{
	edges[cnt_query].to = v;
	edges[cnt_query].next = head_query[u];
	head_query[u] = cnt_query;
	if(DEBUG)
		printf("addquery %d -> %d ,cnt: %d\n",u,v,cnt_query);
	++cnt_query;
}

int main()
{
	int x,y;

	scanf("%d %d %d",&M,&N,&S);

	for(int i = 0;i < N - 1;++i)
	{
		scanf("%d %d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}

	for(int i = 0;i < M;++i)
	{
		scanf("%d %d",&x,&y);
		addquery(x,y);
		addquery(y,x);
	}

	if(DEBUG)
		puts("\n");

	tarjan(S);

	for(int i = 0;i < M; ++i)
		printf("%d\n",ans[i]);

	if(DEBUG)
	{
		puts("\n");
		for(int i = 0;i <= N;++i)
			printf("vi: %d ",visited[i]);
	}

	return 0;
}
