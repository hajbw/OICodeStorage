/*
	P1719 最大加权矩形
	AC
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 128;

int N,sum[MAXN][MAXN],curr,ans = -19260817;

template<class T>inline T max(const T &a,const T &b)
{
	return a > b ? a : b;
}

int main()
{
	cin>>N;
	for(int i = 1;i <= N;++i)
	{
		for(int j = 1;j <= N;++j)
		{
			cin>>curr;
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + curr;
		}
	}

	/*for(int i = 1;i <= N;++i)
	{
		for(int j = 1;j <= N;++j)
			cout<<sum[i][j]<<'\t';
		cout<<'\n';
	}*/

	for(int i1 = 1;i1 <= N;++i1)
		for(int j1 = 1;j1 <= N;++j1)
			for(int i2 = 0;i2 < i1;++i2)
				for(int j2 = 0;j2 < j1;++j2)
					ans = max(ans,sum[i1][j1] - sum[i1][j2] - sum[i2][j1] + sum[i2][j2]);

	cout<<ans;

	return 0;
}