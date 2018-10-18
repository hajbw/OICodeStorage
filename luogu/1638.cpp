/*
	P1638 逛画展
	AC
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 1000010,MAXM = 2018;

int arr[MAXN],cnt[MAXM];
int N,M,a,b,l,r,len = 19260817,len_curr,now;

template<class T>T min(const T &a,const T &b)
{
	return a < b ? a : b;
}

int main()
{
	cin>>N>>M;
	for(int i = 1;i <= N;++i)
		cin>>arr[i];

	for(l = 1,r = 0;l <= N;)
	{
		while(now < M && r < N)
		{
			++r;
			if(!cnt[arr[r]])
				++now;
			++cnt[arr[r]];
		}
		if(now < M)
			break;
		if((len_curr = r - l + 1) < len)
		{
			len = len_curr;
			a = l;
			b = r;
		}
		if(len == M)
			break;
		--cnt[arr[l]];
		if(!cnt[arr[l]])
			--now;
		++l;
	}

	cout<<a<<' '<<b;

	return 0;
}