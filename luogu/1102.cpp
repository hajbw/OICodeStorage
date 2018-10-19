/*
	P1102 A−B数对
	AC
*/
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXN = 200010;

int N,C,a,arr[MAXN],num[MAXN],cnt[MAXN],inum,l = 1,r = 1,lastr;
long long ans;

int main()
{
	cin>>N>>C;
	for(int i = 0;i < N;++i)
		cin>>arr[i];

	std::sort(arr,arr + N);

	for(int i = 0;i < N;++i)
	{
		if(arr[i] != num[inum])
			num[++inum] = arr[i];
		++cnt[inum];
	}

	// for(int i = 0;i <= inum;++i)
	// 	cout<<num[i]<<'\t'<<cnt[i]<<'\n';

	while(l <= inum)
	{
		for(;num[r] - num[l] <= C && r <= inum;++r)
			if(num[r] - num[l] == C)
				ans += (long long)cnt[l] * cnt[r];

		++l;
	}

	cout<<ans;

	return 0;
}