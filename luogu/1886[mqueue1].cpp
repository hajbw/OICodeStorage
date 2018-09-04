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

	node():value(),index(),prev(),next(){}
	node(int v,int i):value(v),index(i),prev(),next(){}
	node(int v,int i,node *p,node *n):value(v),index(i),prev(p),next(n){}
}
*head,*tail,*temp;

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
		//kick tail nodes out
		while(tail && (reverse ? tail->value < num[i] : tail->value > num[i]))
		{
			tail = tail->prev;
			delete tail->next;
		}
		//push num[i] in the back
		temp = tail;
		tail = new node(num[i],i);
		if(temp)
		{
			tail->prev = temp;
			temp->next = tail;
		}
		else
			head = tail;

		if(head->index <= i - K)
		{
			if(head)
			{
				temp = head;
				head = head->next;
				delete temp;
				if(!head)
					tail = NULL;
			}
		}

		if(i > K - 2)
			cout<<head->value<<" ";
	}
}

int main()
{
	read(N);read(K);
	for(int i = 0;i < N;++i)
		read(num[i]);

	get_min(0);
	cout<<"\n";
	get_min(1);

	system("pause");

	return 0;
}