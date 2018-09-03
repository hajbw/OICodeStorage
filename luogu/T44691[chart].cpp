#include <iostream>

/**
	T44691 无限序列 
*/

using std::cin;
using std::cout;

struct node
{
	int stat;
	node *next;

	node():stat(),next(){}
	node(int a):stat(a),next(){}
	node(int a,node *ne):stat(a),next(ne){}
}
*head;

void printlist()
{
	for(node *it = head;it;it = it->next)
		cout<<it->stat;
	cout<<std::endl;
}

void opreate()
{
	for(node *it = head;it;it = it->next)
	{
		if(it->stat)
		{
			it->next = new node(0,it->next);
			it = it->next;
		}
		else
			it->stat = 1;
	}
}

int main()
{
	head = new node(1);

	//printlist();
	for(int i = 0;i < 100;++i)
	{
		opreate();
		//printlist();
	}
	printlist();

	return 0;

}