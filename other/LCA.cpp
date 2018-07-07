#include <iostream>

/*
	P3379【模板】最近公共祖先（LCA）
*/

#define child(node) (node<<1)
#define next(node) (node<<1|1)
#define val(node) (tree[node])

const int MAXN = 500000,MAXM = 500000;

int fa[MAXN],tree[MAXN << 2 | 2],target_a[MAXM],target_b[MAXM];
int M,N,S;

int union_find(int x)
{
	while(f[x] != f[f[x]])
		x = f[x] = f[f[x]];
	return x;
}

int main()
{
	return 0;
}