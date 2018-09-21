/*
	T46332 数列(sequence)
*/

#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 1005;

int main()
{
	int
		N,ans = 0,
		*arr	= new int[MAXN],
		*diff	= new int[MAXN],
		**buck	= new int[MAXN][MAXN<<4],
		**dp	= new int[MAXN][MAXN];

	cin>>N;

	for(int i = 0;i < N;++i)
	{
		cin>>arr[i];
		diff[i] = arr[i] - i;
		for(int j = 0;j < N;++j)
			++buck[j][diff[i]];
	}

	for(int i = 1;i < N;++i)
	{
		for(int j = 1;j < i;++j)
		{
			dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1] + buck[i][])
		}
	}

	cout<<ans;

	return 0;
}