/*
	P3372 【模板】线段树 1
*/

#include <iostream>

#define lch(n)	(n<<1)
#define rch(n)	(n<<1|1)
#define fa(n)	(n>>1)

using std::cin;
using std::cout;

typedef long long num_t;

const int MAXM = 100010,MAXN = 100010;

struct node
{
	int lb,rb;
	num_t val,tag;
}
tree[MAXN<<2];

num_t arr[MAXN];
int M,N;

void add(node *n,const int &lb,const int &rb,const num_t &k)
{
	if(lb =  n->lb)
	{
		n->val += k;
		return;
	}

	if

}

num_t query(const int &node,const int &lb,const int &rb)
{

}

int main()
{
	int a,b,c;

	cin>>N>>M;
	for(int i = 0;i < N;++i)
		cin>>arr[i];

	build_tree();

	for(int i = 0;i < M;++i)
	{
		cin>>a;
		if(a == 1)
		{
			cin>>a>>b>>c;
			add(tree+1,a,b,c);
		}
		else
		{
			cin>>a>>b;
			cout<<query(tree+1,a,b);
		}
	}
}