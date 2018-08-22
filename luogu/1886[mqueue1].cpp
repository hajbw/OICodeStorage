#include <iostream>

/**
	P1886 滑动窗口
	ver.1
	using user-defined monotone queue
	homotone queue(大嘘)
*/

using std::cin;
using std::cout;

const int MAXN = 1000010;

struct node
{
	int value,index;
	node *prev,*next;

	node(){}
	node(int v,int i,node *p,node *n):value(v),index(i),prev(p),next(n){}
}
*head,*tail;

int num[MAXN],N,K;

template<class T>void read(T &x,std::istream &in = cin)
{
	char ch;int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

inline void get_min(int reverse)
{

	for(int i = 0;i < N;++i)
	{
		//push in
		while(tail->prev != head && (reverse ^ tail->prev->value > num[i]))
		{
			tail->prev = tail->prev->prev;
			delete tail->prev->next;//now tail->prev->prev->next
			tail->prev->next = tail;
		}
		

	}
}

int main()
{
	head = new node();
	tail = new node();
	head->next = tail;
	tail->prev = head;

	read(N);read(K);
	for(int i = 0;i < N;++i)
		read(num[i]);

	get_min(0);
	cout<<"\n";
	get_min(1);

	return 0;
}