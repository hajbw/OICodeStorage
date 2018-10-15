/*
	P3372 【模板】线段树 1
*/

#include <iostream>

#define DEBUG 1

#define fa(n)	(n>>1)
#define lch(n)	(n<<1)
#define rch(n)	(n<<1|1)
#define l(n)	(tree[n].lb)
#define r(n)	(tree[n].rb)
#define val(n)	(tree[n].val)
#define tag(n)	(tree[n].tag)

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

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

void build_tree(int n,const int &lb,const int &rb);
void add(int n,const int &lb,const int &rb,const num_t &k);
num_t query(int n,const int &lb,const int &rb);

num_t arr[MAXN];
int M,N;

void add(int n,const int &lb,const int &rb,const num_t &k)
{
	if(rb < l(n) || lb > r(n))
		return;
	else if(lb <= l(n) && rb >= r(n))
		tag(n) += k;
	else
	{
		if(rb >= l(rch(n)))
			add(rch(n),lb,rb,k);
		if(lb <= r(lch(n)))
			add(lch(n),lb,rb,k);
	}

#if DEBUG

	cout<<n<<'\t'<<query(1,n,n)<<'\t'<<tag(n)<<'\n';

#endif
}

num_t query(int n,const int &lb,const int &rb)
{
	if(rb < l(n) || lb > r(n))
		return 0;

	if(l(n) >= lb && r(n) <= rb)
		return val(n) + tag(n) * (r(n) - l(n) + 1);

	return query(lch(n),lb,rb) + query(rch(n),lb,rb) + tag(n) * (min(rb,r(n)) - max(lb,l(n)) + 1);
}

void build_tree(int n,const int &lb,const int &rb)
{
	tree[n] = (node){lb,rb};

	if(lb == rb)
	{
		val(n) = arr[lb];
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
	for(int i = 1;i <= N;++i)
		cin>>arr[i];

	build_tree(1,1,N);

#if DEBUG

#endif

	for(int i = 0;i < M;++i)
	{
		cin>>a>>x>>y;
		if(a == 1)
		{
			cin>>k;
			add(1,x,y,k);
		}
		else
			cout<<query(1,x,y)<<'\n';

#if DEBUG

		for(int i = 1;i <= N;++i)
			cout<<query(1,i,i)<<'\t';
		cout<<'\n';

#endif
	}

	return 0;
}