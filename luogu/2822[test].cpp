/**
	P2822 组合数问题
	tester
*/
#include <iostream>

#define DEBUG 1

#define min(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

const int MAXN = 2018;

unsigned long long C[MAXN][MAXN];

int main()
{
	int n,k;

	cin>>n>>k;

	for(int i = 0;i < n;++i)
		C[i][1] = C[1][i] = 1;

	for(int i = 2;i < n;++i)
		for(int j = 2;j <= i;++j)
			cout<<i<<'\t'<<j<<'\t'<<(C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % k)<<'\n';

	return 0;
}