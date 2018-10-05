/*
	小奇的数列(seq)
	brute-force
*/
#include <iostream>
#include <algorithm>

#define DEBUG 0

using std::cin;
using std::cout;

typedef long long num_t;

const int MAXN = 100010,MAXM = 10010;

num_t a[MAXN],sum[MAXN];

template<class T>inline T min(const T &a,const T &b)
{
	return a < b ? a : b;
}

int main()
{
	int M,N,l,r,P;
	num_t ans;

#if !DEBUG
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
#endif

	cin>>N>>M;

	for(int i = 1;i <= N;++i)
	{
		cin>>a[i];
		sum[i] = a[i] + sum[i - 1];
	}

#if DEBUG

	for(int i = 0;i < N;++i)
		cout<<a[i]<<'\t'<<sum[i]<<'\n';

#endif

	for(int i = 0;i < M;++i)
	{
		cin>>l>>r>>P;
		ans = 2147483647;
		for(int i = l;i <= r;++i)
			for(int j = i;j <= r;++j)
				ans = min(ans,(sum[j] - sum[i - 1]) % P);

		cout<<ans<<'\n';
	}

	return 0;
}