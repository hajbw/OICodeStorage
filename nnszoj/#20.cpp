#include <iostream>

/*
	#20. 二叉搜索树
*/

using std::cin;
using std::cout;
using std::endl;

const int MAXN = 100;

struct node
{
	int data,left,right;

	node(int data,int left,int right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}

	node()
	{
		left = 0;
		right = 0;
	}

}tree[MAXN];

int index = 0;

int insert(int root,int data)
{
	if(!root)
	{
		++index;
		tree[index].data = data;
		return index;
	}

	if(data > tree[root].data)
		tree[root].right = insert(tree[root].right,data);
	else
		tree[root].left = insert(tree[root].left,data);

	return root;
}

void LNR(int root)//front
{
	if(!root)
		return;
	LNR(tree[root].left);
	cout<<tree[root].data<<" ";
	LNR(tree[root].right);
}

void NLR(int root)//mid
{
	if(!root)
		return;
	cout<<tree[root].data<<" ";
	NLR(tree[root].left);
	NLR(tree[root].right);
}

void LRN(int root)//post
{
	if(!root)
		return;
	LRN(tree[root].left);
	LRN(tree[root].right);
	cout<<tree[root].data<<" ";
}

int main()
{
	int root = 0,n = 0,temp;

	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		root = insert(root,temp);
	}

	LNR(1);
	cout<<endl;
	NLR(1);
	cout<<endl;
	LRN(1);

	return 0;
}
