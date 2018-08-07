#include <iostream>

/**
	P1439 【模板】最长公共子序列
*/

#define max(a,b) (a > b ? a : b)

using std::cin;
using std::cout;
using std::istream;

const int MAXN = 1080;

int a[MAXN],b[MAXN],dp[MAXN][MAXN];

template<class T> void read(istream &in,T &x)
{
	char ch = '\0';
	int flag = 0;
	x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9')
	{
		flag ^= (ch == '-');
		in.get(ch);
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch-'0');
		in.get(ch);
	}
	if(flag)
		x = -x;
}

int main()
{
	int n;

	read(cin,n);
	for(int i = 0;i < n;++i)
		read(cin,a[i]);
	for(int i = 0;i < n;++i)
		read(cin,b[i]);

	for(int i = 0;i < n;++i)
	{
		for(int j = 0;j < n;++j)
		{
			dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
			if(a[i] == b[j])
				dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
		}
	}

	cout<<dp[n - 1][n - 1];

	return 0;
}