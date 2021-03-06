#include <iostream>

#define l(node)		(tree[node].left)
#define r(node)		(tree[node].right)
#define val(node)	(tree[node].val)
#define del(node)	(tree[node].delay)

/*
	P3372 【模板】线段树 1
*/

using std::cin;
using std::cout;
using std::endl;

const int MAXM = 100000,MAXN = 100001;

typedef long long int num;

struct Node
{
	int left,right;
	num val,delay;
}
tree[MAXN << 2 | 2];

num arr[MAXN];

void build_tree(int node,int left,int right)
{
	l(node) = left;
	r(node) = right;

	if(left == right)
	{
		val(node) = arr[left];
		return;
	}

	int mid = (left + right) >> 1;

	build_tree(node << 1,left,mid);
	build_tree(node << 1 | 1,mid + 1,right);

	val(node) = val(node << 1) + val(node << 1 | 1);
}

void add(int node,int left,int right,num k)
{
	if(l(node) == left && r(node) == right)
	{
		del(node) += k;
		return;
	}

	int mid = (l(node) + r(node)) >> 1;

	if(right <= mid)
	{
		add(node << 1,left,right,k);
		return;
	}
	if(left > mid)
	{
		add(node << 1 | 1,left,right,k);
		return;
	}

	add(node << 1,left,mid,k);
	add(node << 1 | 1,mid + 1,right,k);
}

num query(int node,int left,int right)
{
	if(l(node) == left && r(node) == right)
		return val(node) + del(node) * (r(node) - l(node) + 1ll);

	int mid = (l(node) + r(node)) >> 1;
	
	if(right <= mid)
		return query(node << 1,left,right);
	if(left > mid)
		return query(node << 1 | 1,left,right);

	return
		query(node << 1,left,mid) +
		query(node << 1 | 1,mid + 1,right);
}

template<class T>void read(T &x)
{
	char ch;
	int sign = 0;
	x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9')
	{
		sign ^= (ch == '-');
		ch.get(ch);
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + ch - '0';
		cin.get(ch);
	}
	if(sign)
		x = ~x + 1;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int op_type,x,y,M,N;
	num k;

	cin>>N>>M;

	for(int i = 1;i <= N;++i)
		cin>>arr[i];

	build_tree(1,1,N);

	for(int i = 0;i < M;++i)
	{
		cin>>op_type;
		if(op_type == 1)
		{
			cin>>x>>y>>k;
			add(1,x,y,k);
		}
		else
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<endl;
		}
	}

}
