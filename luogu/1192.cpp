/*
	P1192 台阶问题
	AC
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 100010,MAXK = 105,cultry = 100003;

int ans[MAXN];

int main()
{
	int N,K;

	cin>>N>>K;
	ans[0] = 1;
	for(int i = 1;i <= N;++i)
	{
		for(int j = 1;j <= K && i - j >= 0;++j)
		{
			ans[i] += ans[i - j];
			ans[i] %= cultry;
		}
	}

	cout<<ans[N];

	return 0;
}