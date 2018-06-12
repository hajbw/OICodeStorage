#include <iostream>

/*
	P3373 【模板】线段树 1
*/

using std::cin;
using std::cout;
using std::endl;

const int 
	MAXM = 100000,
	MAXN = 100000,
	OP_ADD = 1,
	OP_OUT = 2;

struct Node
{
	int left,right,sum;
	long long delay;

	Node()
	{
		this->left = 0;
		this->right = 0;
		this->sum = 0;
		delay = 0ll;
	}

}tree[MAXN << 2 | 2];

void bulid_tree(int index,int left,int right);
void add(int index,int left,int right,long long num);
long long query(int index,int left,int right);

int M,N,arr[MAXN];

int main()
{
	std::ios::sync_with_stdio(false);

	int op_type,x,y;
	long long k;

	cin>>x>>y;

	for (int i = 0; i < N; ++i)
		cin>>arr[i];

	bulid_tree(1,1,N);

	for (int i = 0; i < M; ++i)
	{
		cin>>op_type;
		if(op_type == OP_ADD)
		{
			cin>>x>>y>>k;
			add(1,x,y,k);
		}
		else
		{
			cin>>x>>y;
			cout<<query(1,x,y);
		}
	}

	return 0;
}

void bulid_tree(int index,int left,int right)
{
	tree[index].left = left;
	tree[index].right = right;
	if(left == right)
	{
		tree[index].sum = arr[left];
		return;
	}
	int mid = left + right >> 1;
	bulid_tree(index << 1 ,left,mid);
	bulid_tree(index << 1 | 1,mid + 1,right);
	tree[index].sum = tree[index << 1].sum + tree[index << 1 | 1].sum;
}

void add(int index,int left,int right,long long num)
{
	if(tree[index].left == left && tree[index].right == right)
		tree[index].delay += num;
	
	int mid = tree[index].left + tree[index].right >> 1;

	if(right <= mid)
	{
		add(index << 1,left,right,num);
		return;
	}
	if(left > mid)
	{
		add(index << 1 | 1,left,right,num);
		return;
	}
	
	add(index << 1,left,mid,num);
	add(index << 1 | 1,mid + 1,right,num);
}

long long query(int index,int left,int right)
{
	if(tree[index].left == left && tree[index].right == right)
		return
			tree[index].sum +
			tree[index].delay * (right - left + 1);

	int mid = tree[index].left + tree[index].right >> 1;

	if(right <= mid)
		return
			query(index << 1,left,right) + 
			tree[index].delay * (right - left + 1);
	if(left > mid)
		return
			query(index << 1 | 1,left,right) +
			tree[index].delay * (right - left + 1);

	return 
		query(index << 1,left,mid) +
		query(index << 1 | 1,mid + 1,right) +
		tree[index].delay * (right - left + 1);
}