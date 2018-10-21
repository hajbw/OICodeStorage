/*
	P1719 最大加权矩形
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 128;

int N,matrix[MAXN][MAXN],sum[MAXN][MAXN];

int main()
{
	cin>>N;
	for(int i = 1;i <= N;++i)
	{
		for(int j = 1;j <= N;++j)
		{
			cin>>matrix[i][j];
			sum[i][j] = sum[i][j - 1] + matrix[i][j];
		}
	}
}