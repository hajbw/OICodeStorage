#include <iostream>
#include <deque>

#define DEBUG 1

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

inline void get_min(bool reverse)
{
	deque<hpair> quq;

	for(int i = 0;i < N;++i)
	{
		while(quq.size() > 1 && (reverse ? quq.back().value < num[i] : quq.back().value > num[i]))
			quq.pop_back();
		quq.push_back(hpair(num[i],i));

		if(quq.size() > 1 && quq.front().index <= i - K)
			quq.pop_front();

		if(i > K - 2)
			cout<<quq.front().value<<" ";
	}
}

int main()
{
	read(N);read(K);
	for(int i = 0;i < N;++i)
		read(num[i]);

	get_min(false);
	cout<<"\n";
	get_min(true);

#if DEBUG
	system("pause");
#endif

	return 0;
}