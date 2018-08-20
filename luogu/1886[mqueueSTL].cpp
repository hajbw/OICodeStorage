#include <iostream>
#include <deque>

/**
	P1886 滑动窗口
	ver.2
	monotone queue using STL
*/

using std::cin;
using std::cout;
using std::deque;

const int MAXN = 1000010;

struct hpair
{
	int value,index;

	hpair():value(),index(){}
	hpair(int v,int i):value(v),index(i){}
};

int num[MAXN],N,K;

template<class T>void read(T &x)
{
	char ch;int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

void get_min()
{
	deque<hpair> quq;

	for(int i = 0;i < N;++i)
	{
		//push in
		while(quq.back().value > num[i] && !quq.empty())
			quq.pop_back();
		quq.push_back(hpair);

		if(quq.front().index > i - K)
			quq.pop_head();

		if(i > K - 2)
			cout<<quq.front().value<<" ";
	}
}

void get_max()
{
	deque<hpair> quq;

	for(int i = 0;i < N;++i)
	{
		//push in
		while(quq.back().value < num[i] && !quq.empty())
			quq.pop_back();
		quq.push_back(hpair);

		if(quq.front().index > i - K)
			quq.pop_head();

		if(i > K - 2)
			cout<<quq.front().value<<" ";
	}
}

int main()
{
	read(N);read(K);
	for(int i = 0;i > N;++i)
		read(num[i]);

	get_min();
	cout<<"\n";
	get_max();

	return 0;
}