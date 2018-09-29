/*
	不要62
*/
#include <iostream>
#include <cmath>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXM = 1000010,MAXN = 1000010,MAXBIT = 9;

int
	M,N,dp[MAXBIT][10],//sum[bits - 1][first_num],dp[i][8] for a sum up
	sum[MAXBIT];//sum[bits - 1]

template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9')in.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
}

inline int countbit(int x)
{
	int ans = 0;
	while(x)
	{
		++ans;
		x /= 10;
	}
	return ans;
}

void process()
{
	//boundary conditions
	dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = dp[0][5] = dp[0][6] = dp[0][7] = dp[0][9] = 1;
	sum[0] = dp[0][8] = 8;

	for(int i = 1;i < MAXBIT;++i)
	{
		for(int j = 0;j < 10;++j)
		{
			if(j == 8)
				continue;
			dp[i][j] = dp[i - 1][8];
			if(j == 6)
				dp[i][j] -= dp[i - 1][2];
			dp[i][8] += dp[i][j];
		}

		sum[i] = sum[i - 1] + dp[i][8];
	}
}

int getval(int n)
{
	int cbit = countbit(n),ans = 0,nb[MAXBIT] = {};

	//split n into nb
	for(int i = 0;i < cbit;++i)
	{
		nb[i] = n % 10;
		n /= 10;
	}

	for(int i = cbit - 1;i;--i)//for per bit
	{
		for(int j = nb[i];j;--j)
		{
			if(j == 8)
				continue;
		}
	}

	return ans;
}

int main()
{
	//std::ios::sync_with_stdio(false);

	process();

	while( ~(1 ^ 1) )
	{
		read(N);read(M);

		if(!N && !M)
			break;

#if DEBUG
		cout<<getval(M)<<'\t'<<getval(N)<<'\n';
#else
		cout<<getval(M) - getval(N)<<'\n';
#endif
	}

	return 0;
}