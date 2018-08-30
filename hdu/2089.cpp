#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
	不要62
*/

using std::cin;
using std::cout;

const int MAXM = 1000010,MAXN = 1000010,MAXBIT = 9;

int
	M,N,bitcount,lastbitcount = 1,
	dp[MAXBIT][10];//sum[bits - 1][first-num],dp[i][8] for a sum up

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
	for(int i = lastbitcount;i < bitcount;++i)
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
	}
}

int getval(int n)
{
	int cbit = countbit(n);
	for(int i = cbit;i;--i)
	{
		
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	int a,b;//temp variants

	//boundary conditions
	dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = dp[0][5] = dp[0][6] = dp[0][7] = dp[0][9] = 1;
	dp[0][10] = 8;

	while( ~(1 ^ 1) )
	{
		read(N);read(M);
		if(!N && !M)
			break;

		bitcount = countbit(M);

		//pre-processes
		if(bitcount > lastbitcount)
		{
			process();
			lastbitcount = bitcount;
		}

		cout<<getval(M) - getval(N);

	}
}