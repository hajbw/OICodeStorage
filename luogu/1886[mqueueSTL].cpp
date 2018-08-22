#include <iostream>
#include <deque>

#define DEBUG 1

#if DEBUG
#include <windows.h>
#endif

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

template<class T>void read(T &x,std::istream &in = cin)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';in.get(ch);}
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
		quq.push_back(hpair(num[i],i));

		if(quq.front().index > i - K)
			quq.pop_front();

		if(i > K)
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
		quq.push_back(hpair(num[i],i));

		if(quq.front().index > i - K)
			quq.pop_front();

		if(i > K)
			cout<<quq.front().value<<" ";
	}
}

int main()
{
	int a;

	read(N);read(K);K -= 2;
	for(int i = 0;i < N;++i)
		read(a),num[i] = a;

	get_min();
	cout<<"\n";
	get_max();

#if DEBUG
	system("pause");
#endif

	return 0;
}