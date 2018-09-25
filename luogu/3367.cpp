/*
	P3367 【模板】并查集
	AC
*/

#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 10010,MAXM = 200020;

int fa[MAXM];

int find(const int &k)
{
	return fa[k] == k ? k : fa[k] = find(fa[k]);
}

int main()
{
	int M,N,x,y,z;

	cin>>N>>M;
	for(int i = 1;i <= N;++i)
		fa[i] = i;
	for(int i = 0;i < M;++i)
	{
		cin>>z>>x>>y;
		if(z == 2)
			cout<<(find(x) == find(y) ? "Y\n" : "N\n");
		else
			fa[find(x)] = find(y);
	}

	return 0;
}