/*
	P3372 【模板】线段树 1
*/

#include <iostream>

#define fa(n)	(n>>1)
#define lch(n)	(n<<1)
#define rch(n)	(n<<1|1)
#define l(n)	(tree[n].lb)
#define r(n)	(tree[n].rb)
#define val(n)	(tree[n].val)
#define tag(n)	(tree[n].tag)

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

void add(const int &n,const int &lb,const int &rb,const num_t &k)
{
	if(lb == l(n) && rb == r(n))
	{
		tag(n) += k;
		return;
	}

	int mid = (lb + rb) >> 1;

	if(rb <= mid)
		add(lch(n),lb,rb,k);
	else if(lb > mid)
		add(rch(n),lb,rb,k);
	else
		add(lch(n),lb,mid,k),
		add(rch(n),mid+1,rb,k);

}

num_t query(const int &n,const int &lb,const int &rb)
{
	if(l(n) == lb && r(n) == rb)
		return val(n) + tag(n) * (rb - lb + 1);

	int mid = (l(n) + r(n)) >> 1;

	if(rb <= mid)
		return query(lch(n),lb,rb);
	else if(lb > mid)
		return query(rch(n),lb,rb);
	else
		return query(lch(n),lb,mid) + query(rch(n),mid+1,rb);

}

void build_tree(const int &n,const int &lb,const int &rb)
{
	tree[n] = (node){lb,rb};

	if(lb == rb)
	{
		tree[n].val = arr[lb];
		return;
	}

	int mid = (lb + rb) >> 1;

	build_tree(lch(n),lb,mid);
	build_tree(rch(n),mid+1,rb);

	val(n) = val(lch(n)) + val(rch(n));
}

int main()
{
	int a,b,c;

	cin>>N>>M;
	for(int i = 0;i < N;++i)
		cin>>arr[i];

	build_tree(1,1,N);

	for(int i = 0;i < M;++i)
	{
		cin>>a;
		if(a == 1)
		{
			cin>>a>>b>>c;
			add(1,a,b,c);
		}
		else
		{
			cin>>a>>b;
			cout<<query(1,a,b);
		}
	}

	return 0;
}