#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
	P1220 关路灯
*/

using std::cin;
using std::cout;

const int MAXN = 55;

int
	power[MAXN],power_sum[MAXN],pos[MAXN],
	dp[MAXN][MAXN][2];//least-used-power[lbound][rbound][left/right]


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
	std::ios::sync_with_stdio(false);

	int N,C,a;

	read(N);read(C);--C;
	read(pos[0]);read(power[0]);
	power_sum[0] = power[0];
	for(int i = 1;i < N;++i)
	{
		read(pos[i]);read(power[i]);
		power_sum[i] = power_sum[i - 1] + power[i];
	}

	for(int i = 0;i < N;++i)
		for(int j = 0;j < N;++j)
			dp[i][j][0] = dp[i][j][1] = 19260817;

	dp[C][C][0] = dp[C][C][1] = 0;

	for(int j = C;j < N;++j)
	{
		for(int i = j - 1;i >= 0;--i)
		{
			a = power_sum[N - 1] - power_sum[j] + power_sum[i];
			dp[i][j][0] = min
			(
				dp[i + 1][j][0] + (pos[i + 1] - pos[i]) * a,
				dp[i + 1][j][1] + (pos[j] - pos[i]) * a
			);
			a = power_sum[N - 1] - power_sum[j - 1] + power_sum[i - 1];
			dp[i][j][1] = min
			(
				dp[i][j - 1][0] + (pos[j] - pos[i]) * a,
				dp[i][j - 1][1] + (pos[j] - pos[j - 1]) * a
			);
		}
	}

	cout<<min(dp[0][N - 1][0],dp[0][N - 1][1]);

	return 0;
}