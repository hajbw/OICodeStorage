/**
	P2822 组合数问题
*/

#include <iostream>

#define DEBUG 1

#define min(a,b) ((a) < (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 2018;

unsigned long long C[MAXN][MAXN];

int main()
{
	int t,n,m,o,k,ans;

	for(int i = 0;i < MAXN;++i)
		C[i][0] = C[0][i] = 1;

	cin>>t>>k;

	for(int i = 1;i < MAXN;++i)
		for(int j = 1;j <= i;++j)
			cout<<i<<'\t'<<j<<'\t'<<(C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % k)<<'\n';

	while(t--)
	{
		ans = 0;
		cin>>n>>m;
		for(int i = 0;i < n;++i)
		{
			o = min(i,m);
			for(int j = 0;j < o;++j)
			{
				if(!C[i][j])
				{
					++ans;
#if DEBUG
					cout<<i<<'\t'<<j<<'\n';
#endif
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}