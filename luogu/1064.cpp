/*
	P1064 金明的预算方案
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXM = 64,MAXN = 32100;

struct item
{
	int price,imp,fa;
}
items[MAXN];

int
	M,N,ans,
	dp[MAXN][MAXM];//max-val(money,curr)


template<class T>inline T min(const T &a,const T &b)
{
	return a < b ? a : b;
}

template<class T>inline T max(const T &a,const T &b)
{
	return a > b ? a : b;
}

int main()
{
	int v,p,q;

	cin>>N>>M;

	for(int i = 1;i <= M;++i)
	{
		cin>>v>>p>>q;
		items[i] = (item){v,v * p,q};
	}

	for(int i = 1;i <= M;++i)
	{
		item it = items[i];
		//dirty fix : if undefined dp[][it.fa],calculate it.fa first
		if(it.fa && !dp[M][it.fa])
		{
			int i = it.fa;
			item it = items[i];
			for(int j = N;j >= it.price + items[it.fa].price;--j)
			{
				dp[j][i] = dp[j - it.price][it.fa] + it.imp;
				dp[j][0] = max(dp[j][0],dp[j][i]);
			}
		}
		//and that if defined dp[][],continue
		if(dp[M][i])
			continue;
		for(int j = N;j >= it.price + items[it.fa].price;--j)
		{
			dp[j][i] = dp[j - it.price][it.fa] + it.imp;
			dp[j][0] = max(dp[j][0],dp[j][i]);
		}
	}

	cout<<dp[N][0];

	return 0;
}