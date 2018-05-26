#include <iostream>

/*
	#16. 第一类斯特林数
	AC
*/

using std::cin;
using std::cout;

typedef unsigned long long num;

const int mo = 10000007;//ha

num stir[500][500];

int main()
{
	num m,n;

	cin>>n>>m;

	for (int i = 0; i <= m; ++i)
		stir[i][i] = 1;

	for (int i = 2; i <= n; ++i)
		for (int j = 1; j <= m && j < i + 1; ++j)
			stir[i][j] = ( stir[i - 1][j - 1] + stir[i - 1][j] * (i - 1) ) % mo;

	cout<<stir[n][m];

}
