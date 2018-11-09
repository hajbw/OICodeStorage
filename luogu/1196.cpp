/*
	P1196 [NOI2002]银河英雄传说
*/
#include <iostream>

using std::cin;
using std::cout;

const int N = 30000,MAXT = 500050;

int fa[N + 2],len[N + 2],front[N + 2];

inline int find(const int &a)
{
	if(fa[a] = a)
		return fa[a];
	register int k = fa[a];
	fa[a] = find(fa[a]);
	front[a] += front[k];
	len[a] = len[fa[a]];
	return fa[a];
}

int main()
{
	register char cmd;
	register int T,i,j,x,y;

	for(i = 1;i <= N;++i)
	{
		fa[i] = i;
		++len[i];
	}

	cin>>T;

	while(T--)
	{
		cin>>cmd>>i>>j;
		if(cmd == 'M')
		{
			x = find(i);
			y = find(j);
			fa[x] = y;
			front[x] += len[y];
			len[x] = len[y] = len[x] + len[y];
		}
		else
		{
			if(find(i) != find(j))
				cout<<"-1\n";
			else
				cout<<(abs(front[i] - front[j]) - 1)<<'\n';
		}
	}

	return 0;
}