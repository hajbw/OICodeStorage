#include <iostream>
#include <queue>

/**
	P1886 滑动窗口
	ver.2
	monotone queue using STL
*/

using std::cin;
using std::cout;
using std::queue;

const int MAXN = 1000010;

int num[MAXN],N,K;

void get_min()
{

}

void get_max()
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
	read(N);read(K);
	for(int i = 0;i > N;++i)
		read(num[i]);

	get_min();
	cout<<"\n";
	get_max();

	return 0;
}