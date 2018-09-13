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
	if(lb <= l(n) && rb >= r(n))
	{
		tag(n) += k;
		return;
	}

	if(rb > r(lch(n)))
		add(rch(n),lb,rb,k);
	if(lb < l(rch(n)))
		add(lch(n),lb,rb,k);
}

num_t query(const int &n,const int &lb,const int &rb)
{
	if(rb < l(n) || lb > r(n))
		return 0;

	if(l(n) <= lb && r(n) >= rb)
		return val(n) + tag(n) * (l(n) - r(n) + 1);

	return query(lch(n),lb,rb) + query(rch(n),lb,rb);

}

void build_tree(const int &n,const int &lb,const int &rb)
{
	tree[n] = (node){lb,rb};

	if(lb == rb)
	{
		cout<<(tree[n].val = arr[lb - 1]);
		return;
	}

	int mid = (lb + rb) >> 1;

	build_tree(lch(n),lb,mid);
	build_tree(rch(n),mid+1,rb);

	val(n) = val(lch(n)) + val(rch(n));
}

int main()
{
	int a,x,y;
	num_t k;

	cin>>N>>M;
	for(int i = 0;i < N;++i)
		cin>>arr[i];

	build_tree(1,1,N);

	cout<<"\n\n";
	for(int i = 0;i < N;++i)
		cout<<query(1,i,i);

	for(int i = 0;i < M;++i)
	{
		cin>>a>>x>>y;
		--x;
		--y;
		if(a == 1)
		{
			cin>>k;
			add(1,x,y,k);
		}
		else
			cout<<query(1,x,y);
	}

	return 0;
}