#include <iostream>

/**
	P1220 关路灯
*/

using std::cin;
using std::cout;

const int MAXN = 55,;

template<class T1,class T2>struct hpair
{
	T1 first;
	T2 second;
	hpair():first(),second(){}
	hpair(T1 a):first(a),second(){}
	hpair(T1 a,T2 b):first(a),second(b){}
};

int dp[MAXN][MAXN][2];
hpair<int,int> lights[MAXN];


template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

int main()
{
	int N,C,a,b;

	read(N);read(C);
	for(int i = 0;i < N;++i)
	{
		read(a);read(b);
		lights[i] = (lights){a,b};
	}

	return 0;
}