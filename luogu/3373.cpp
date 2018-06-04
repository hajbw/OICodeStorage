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

struct node
{
	int left,right,sum;
};

int main()
{
	int M,N,P;
	int op_type,x,y,k;

	cin>>M>>N>>P;

	for(int i = 0; i < N; ++i)
	{
		//input & build
	}

	for (int i = 0; i < M; ++i)
	{	
		cin>>op_type;
		if(op_type == OP_MUL)
		{

		}
		else if(op_type == OP_ADD)
		{

		}
		else
		{
			
		}
	}

	return 0;
}
