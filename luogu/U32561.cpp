#include <iostream>

/**
	U32561 Zrz_orz Loves Secondary Element
*/

using std::cin;
using std::cout;

const int MAXT = 10010,MAXN = 10010,MAXM = 105;

struct edge
{
	int to,next,w;
}
edges[MAXN*2];

int head[MAXN],edge_cnt = 1,times[MAXT],happiness[MAXN];

inline addedge(int u,int v,int w)
{
	edges[++edge_cnt] = (edge){v,head[u],w};
	head[u] = edge_cnt;
}

template<class T>inline void read(T &x)
{
	char ch = '\0';int flag = 0;x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');cin.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
	if(flag)x = -x;
}

int main()
{
	int M,N,T,u,v,w,a,b;

	read(N);read(M);read(T);
	for(int i = 0;i < N - 1;++i)
	{
		read(u);read(v);read(w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i = 0;i < M;++i)
	{
		read(a);read(b);
		happiness[a] = b;
	}
	for(int i = 0;i < T;++i)
	{
		read()
	}
}