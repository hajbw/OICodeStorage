/*
	P1111 修复公路
	AC
*/
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXN = 1005,MAXM = 100010;

struct htriple
{
	int x,y,t;

	htriple(){}
	htriple(const int &x,const int &y,const int &t):x(x),y(y),t(t){}

	bool operator<(const htriple &a)const
	{
		return t < a.t;
	}

	friend std::istream& operator>>(std::istream &in,htriple &a)
	{
		return in>>a.x>>a.y>>a.t;
	}
}
roads[MAXM];
int N,M,fa[MAXN];

inline int find(int x)
{
	while(fa[x] != fa[fa[x]])
		fa[x] = fa[fa[x]];
	return fa[x];
}

int main()
{
	int a,b;
	htriple *tmp = roads + 1;

	cin>>N>>M;

	for(int i = 1;i <= N;++i)
		fa[i] = i;

	for(int i = 1;i <= M;++i)
		cin>>roads[i];

	std::sort(roads + 1,roads + 1 + M);
	--N;

	for(;tmp - roads <= M;++tmp)
	{
		if((a = find(tmp->x)) == (b = find(tmp->y)))
			continue;

		fa[a] = b;
		--N;

		if(!N)
			break;
	}

	if(N)
		cout<<-1;
	else
		cout<<tmp->t;

	return 0;
}