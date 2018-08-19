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
	node* prev,next;

	node():value(0),prev(),next(){}
};

int min_num[MAXN],max_num[MAXN];

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
	int N,K,num;
	node min_head,min_head;

	read(N);read(K);
	for(int i = 0;i < N;++i)
	{
		read(num);
	}
}