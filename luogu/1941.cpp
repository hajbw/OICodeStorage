/*
	P1941 飞扬的小鸟
*/
#include <iostream>
#include <cstring>

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXN = 10005,MAXM = 1000,INF = 2139062143;

int
	M,N,K,
	X[MAXN],Y[MAXN],up[MAXN],down[MAXN],tube[MAXN],
	dp[MAXN][MAXM];

template<class T>inline const T& min(const T &a,const T &b){return a < b ? a : b;}
template<class T>inline const T& max(const T &a,const T &b){return a > b ? a : b;}

int main()
{
	register int flag,a,i,j;

	cin>>N>>M>>K;
	for(i = 1;i <= N;++i)
		cin>>X[i]>>Y[i];
	for(i = 1;i <= K;++i)
	{
		cin>>a>>down[a]>>up[a];
		tube[a] = 1;
	}

	for(i = 1;i <= M;++i)
		if(!tube[i])
			up[i] = M;

	cout<<'\n';
	for(int i = 0;i <= N;++i)
		cout<<down[i]<<'\t';
	cout<<'\n';
	for(int i = 0;i <= N;++i)
		cout<<up[i]<<'\t';
	cout<<'\n';
	for(int i = 0;i <= N;++i)
		cout<<tube[i]<<'\t';
	cout<<'\n';

	std::memset(dp,127,sizeof(dp));
	std::memset(dp,0,sizeof(dp[0]));

	for(i = 0;i <= N;++i)
	{
		cout<<" i:"<<i<<' ';
		//going up
		for(j = max(down[i] + 1,down[i - 1] + X[i - 1]);j < up[i];++j)
		{
			cout<<" 1j:"<<j<<' ';
			dp[i][j] = min(dp[i - 1][j - X[i - 1]] + 1,dp[i][j - X[i - 1]] + 1);
		}

		//falling down
		a = min(up[i],up[i - 1] - Y[i - 1]);
		//cout<<" a:"<<a<<' ';
		printf(" %d,%d,%d-%d ", a,up[i],up[i - 1],Y[i - 1]);
		for(j = down[i] + 1;j < a;++j)
		{
			cout<<" 2j:"<<j<<' ';
			dp[i][j] = min(dp[i][j],dp[i - 1][j + Y[i - 1]]);
		}

		//specially for upper bound
		//when no pipe,able to touch top
		if(!tube[i])
		{
			for(j = 1;j <= X[i];++j)
				dp[i][M] = max(dp[i][M],dp[i][M - j] + 1);
		}

		//if unable
		for(j = down[i] + 1;j < up[i] && dp[i][j] >= INF;++j) ;

		if(j == up[i])
		{
			a = i;
			flag = true;
			break;
		}
	}

#if DEBUG

	cout<<'\n';

	for(j = M;j >= 0;--j)
	{
		for(i = 0;i <= N;++i)
		{
			if(dp[i][j] >= INF)
				cout<<"INF\t";
			else
				cout<<dp[i][j]<<'\t';
		}
		cout<<'\n';
	}


#endif

	if(flag)
		cout<<"0\n"<<a;
	else
	{
		a = INF;
		for(int i = down[N] + 1;i < up[N];++i)
			a = min(a,dp[N][i]);
		cout<<"1\n"<<a;
	}

	return 0;
}