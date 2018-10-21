/*
	P1941 飞扬的小鸟
*/
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

const int MAXN = 10005,MAXM = 1000;

struct hpair
{
	int x,y;

	friend std::istream& operator>>(std::istream &in,hpair &a)
	{
		return in>>a.x>>a,y;
	}
}
delta[MAXN],//X[x],Y[x]
map[MAXN];//lower_bound[x],upper_bound[x]

int M,N,K,dp[MAXN][MAXM];

int main()
{
	cin>>N>>M>>K;
	for(int i = 1;i <= N;++i)
		cin>>delta[i];
	for(int i = 1,p;i <= K;++i)
		cin>>p>>map[p];

	for(int i = 1;i <= M;++i)
		if(!map[i].y)
			map[i].y = m;

	for(int i = 1;i <= N;++i)
	{
		for(int j = map[i].x;j <= map[i].y;++j)
		{
			
		}

		for(int j = map[i].x;j <= map[i].y;++j)
		{
			
		}
	}
}