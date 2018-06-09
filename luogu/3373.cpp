#include <iostream>

/*
	P3373 【模板】线段树 2
*/

using std::cin;
using std::cout;
using std::endl;

const int 
	MAXM = 100000,
	MAXN = 100000,
	OP_MUL = 1,
	OP_ADD = 2,
	OP_OUT = 3;

struct Node
{
	int left,right,sum;
	long long delay;

	Node(int left,int right,int sum)
	{
		this->left = left;
		this->right = right;
		this->sum = sum;
		delay = 0ll;
	}

	Node()
	{
		Node(0,0,0);
	}

}tree[MAXN * 4 + 2];

void bulid_tree(int index,int left,int right);
void multiply(int index,int left,int right,long long num);
void add(int index,int left,int right,long long num);
int query(int index,int left,int right);

int M,N,P,arr[MAXN];

int main()
{
	int op_type,x,y;
	long long k;

	cin>>M>>N>>P;

	for (int i = 0; i < N; ++i)
		cin>>arr[i];

	bulid_tree(1,1,N);
	
	for (int i = 0; i < M; ++i)
	{	
		cin>>op_type;
		if(op_type == OP_MUL)
		{
			cin>>x>>y>>k;
			multiply(x,y,k);
		}
		else if(op_type == OP_ADD)
		{
			cin>>x>>y>>k;
			add(x,y,k);
		}
		else
		{
			cin>>x>>y;
			cout<<query(x,y);
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
	int mid = (left + right) / 2;
	bulid_tree(index << 1 ,left,mid);
	bulid_tree(index << 1 | 1,mid + 1,right);
	tree[index].sum = tree[index << 1].sum + tree[index << 1 | 1].sum;
}

void multiply(int index,int left,int right,long long num)
{

}

void add(int index,int left,int right,long long num)
{
	if(tree[index].left == left && tree[index].right == right)
		tree[index].delay += num;
}

int query(int index,int left,int right)
{
	if(tree[index].left == left && tree[index].right == right)
		return (tree[index].sum + ) % P;
	
}