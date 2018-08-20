#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))
/**
	contest 1 problem 4 #25
	D. 圣诞树(tree)
*/

using std::cin;
using std::cout;

const int MAXN = 105,BUF_LEN = 400;

struct edge
{
	int to,next;
}
edges[MAXN];

int value[MAXN],tvalue[MAXN],vis[MAXN],head[MAXN],edge_cnt;
char buf[BUF_LEN],ch;

template<class T>void read(T &x)
{
	ch = '\0';x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';cin.get(ch);}
}

inline void addedge(int u,int v)
{
	edges[++edge_cnt] = (edge){v,head[u]};
	head[u] = edge_cnt;
}

int dfs(int n)
{
	vis[n] = 1;
	for(int i = head[n];i;i = edges[i].next)
		tvalue[n] += dfs(edges[i].to);
	return tvalue[n];
}

int main()
{
	int N,a,ans = 0;

	cin>>N;
	for(int i = 0;i < N;++i)
	{
		read(a);
		tvalue[i] = value[i] = a;
		cin.getline(buf,BUF_LEN);
		char *ch = buf;
		while(!(ch == '\0' || ch == '\n'))
		{

		}
	}

	for(int i = 0;i < N;++i)
		if(!vis[i])
			ans = max(ans,dfs(i));

	cout<<ans;

	return 0;
}