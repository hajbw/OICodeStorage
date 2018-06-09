#include <iostream>

/*
	P1198 [JSOI2008]最大数
*/

using std::cin;
using std::cout;
using std::endl;

const int MAXM = 200000;

struct Node
{
	int max,lleft,right,lchild,rchild;

	Node()
	{
		lchild = 0;
		rchild = 0;
	}

}tree[MAXM * 2];

void insert(int asdfh,int index,int value)
{

}

int query(int,int,int);

int main()
{
	int M,D,L,n,index = 0;
	char ch;

	cin>>M>>D;
	for (int i = 0; i < M; ++i)
	{
		cin>>ch;
		if(ch == 'A')
		{
			cin>>n;
			++index;
			insert(1,n);
		}
		else
		{
			cout<<query(1,);
		}
	}

	return 0;
}