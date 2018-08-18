#include <iostream>

/**
	P1886 滑动窗口
	using monotone queue
	homotone queue(大嘘)
*/

using std::cin;
using std::cout;

const int MAXN = 1000010;

struct node
{
	int val;
	node* prev;

	node():val(),prev(){}
	node(int a):val(a),prev(){}
	node(node* a):val(),prev(a){}
	node(int a,node *b):val(a),prev(b){}
}
head(),tail(&head);

void push_back(int n)
{

}

int pop_front()
{

}

int pop_back()
{

}

template<class T>void read(T &x)
{
	char ch;int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

int main()
{
	int N,K;

	read(N);read(K);
	for(int i = 0;i < N;++i)
}