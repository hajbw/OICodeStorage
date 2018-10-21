/**
	P2822 组合数问题
	AC
*/

#include <iostream>

#define DEBUG 1

#define min(a,b) ((a) < (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 2018;

unsigned long long
	C[MAXN][MAXN],
	cntC[MAXN][MAXN];//

int main()
{
	int t,n,m,k,ans;

	cin>>t>>k;

	for(int i = 0;i < MAXN;++i)
		C[i][0] = 1;

	for(int i = 1;i < MAXN;++i)
	{
		for(int j = 1;j <= i;++j)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % k;
			cntC[i][j] = cntC[i][j - 1] + !C[i][j];
		}
	}

/*	for(int i = 0;i < 11;++i)
	{
		for(int j = 0;j <= i;++j)
			cout<<C[i][j]<<'\t';
		cout<<'\n';
	}

	cout<<"\n---------------------------------------\n";

	for(int i = 0;i <= 10;++i)
	{
		for(int j = 0;j <= i;++j)
			cout<<cntC[i][j]<<'\t';
		cout<<'\n';
	}*/

	while(t--)
	{
		ans = 0;
		cin>>n>>m;
		for(int i = 1;i <= n;++i)
			ans += cntC[i][min(i,m)];
		cout<<ans<<'\n';
	}
	
	return 0;
}