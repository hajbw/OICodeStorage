/*
	P1855 榨取kkksc03
	AC
*/
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

const int MAXN = 105,MAXM = 205,MAXT = 205;

struct hpair
{
	int m,t;
	
	friend std::istream& operator>>(std::istream &in,hpair &a)
	{
		return in>>a.m>>a.t;
	}
}
hopes[MAXN];

int dp[MAXM][MAXT],N,M,T;

template<class T>T max(const T &a,const T &b)
{
	return a > b ? a : b;
}

int main()
{
	cin>>N>>M>>T;
	for(int i = 1;i <= N;++i)
		cin>>hopes[i];

	for(int i = 1;i <= N;++i)
		for(int m = M;m >= hopes[i].m;--m)
			for(int t = T;t >= hopes[i].t;--t)
				dp[m][t] = max(dp[m][t],dp[m - hopes[i].m][t - hopes[i].t] + 1);
				// if((a = dp[m - hopes[i].m][t - hopes[i].t] + 1) > dp[m][t])
				// 	cout<<i<<' '<<(dp[m][t] = a)<<'\n';

	cout<<dp[M][T];

	return 0;
}