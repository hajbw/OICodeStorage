/*
	P1536 村村通
	AC
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 1005;

int M,N,fa[MAXN];

inline int find(const int &x)
{
	while(fa[x] != fa[fa[x]])
		fa[x] = fa[fa[x]];
	return fa[x];
}

int main()
{
	int u,v,a,b;

	while( ~(1 ^ 1) )
	{
		cin>>N>>M;

		if(!N)
			break;

		for(int i = 1;i <= N;++i)
			fa[i] = i;

		--N;

		for(int i = 1;i <= M;++i)
		{
			cin>>u>>v;
			if(N && (a = find(u)) != (b = find(v)))
			{
				fa[a] = b;
				--N;
			}
		}

		cout<<N<<'\n';
	}

	return 0;
}