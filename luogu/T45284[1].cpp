/*
	T45284 宝物筛选(Treasure．pas/c/cpp)
	AC
*/

#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;
using std::istream;

const int MAXN = 105,MAXW = 40004,MAXL = 50;

struct good
{
	int val,wei;
}
m[MAXN<<4];

int N,W,im = 0,dp[MAXW];
char buf[MAXL],*ch;

inline int topbit(int x)
{
	int res = 0;
	while(x)
	{
		x >>= 1;
		++res;
	}
	return res;
}

void linefeed()
{
	cin.getline(buf,MAXL);
	ch = buf;
}

template<class T>bool read(T &x)
{
	x = 0;
	while(*ch < '0' || *ch > '9')
	{
		++ch;
		if(!(*ch))
			return false;
	}
	while(*ch >= '0' && *ch <= '9')
	{
		x = (x<<1) + (x<<3) + *ch - '0';
		++ch;
	}
	return true;
}

int main()
{
	int v,w,n;

	linefeed();
	read(N);read(W);
	for(int i = 0;i < N;++i)
	{
		linefeed();
		read(v);read(w);read(n);

		for(int j = 1;j <= n;j <<= 1)
		{
			m[im++] = (good){v * j,w * j};
			n -= j;
		}
		if(n)
			m[im++] = (good){v * n,w * n};
	}

	for(int i = 0;i < im;++i)
	{
		for(int j = W;j >= m[i].wei;--j)
		{
			dp[j] = max(dp[j],dp[j - m[i].wei] + m[i].val);
		}
	}

	cout<<dp[W];

}