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

}tree[MAXM * 2 + 2];

void insert(int asdfh,int index,int value)
{

}

int query(int index,int left,int right);

int main()
{
	int M,D,L,n,t = 0,index = 0;
	char ch;

	cin>>M>>D;
	for (int i = 0; i < M; ++i)
	{
		cin>>ch;
		if(ch == 'A')
		{
			cin>>n;
			++index;
			insert(1,n,);
		}
		else
		{
			cin>>L;
			t = query(1,index - L + 1,index);
			cout<<t;
		}
	}

	return 0;
}