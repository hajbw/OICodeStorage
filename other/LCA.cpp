#include <iostream>

#define l(node) (node<<1)
#define r(node) (node<<1|1)
#define val(node) (tree[node])



const int MAXN = 100

int fa[MAXN],tree[MAXN << 2 | 2];

int LCA(int a,int b)
{

}

int union_find(int x)
{
	while(f[x] != f[f[x]])
		f[x] = f[f[x]];
}

int main()
{
	return 0;
}