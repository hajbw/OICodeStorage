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

int main()
{
	int v,w,n;

	cin>>N>>W;
	for(int i = 0;i < N;++i)
	{
		cin>>v>>w>>n;

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