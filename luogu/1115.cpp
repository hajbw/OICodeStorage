/*
	P1115 最大子段和
	AC
*/
#include <iostream>
#include <climits>

using std::cin;
using std::cout;

const int MAXN = 200020;

int N,curr,sum[MAXN],min_sum,ans = -19260817;

template<class T>T min(const T &a,const T &b)
{
	return a < b ? a : b;
}

template<class T>T max(const T &a,const T &b)
{
	return a > b ? a : b;
}

int main()
{
	cin>>N;

	for(int i = 1;i <= N;++i)
	{
		cin>>curr;
		sum[i] = sum[i - 1] + curr;
	}

	for(int i = 1;i <= N;++i)
	{
		ans = max(ans,sum[i] - min_sum);
		min_sum = min(min_sum,sum[i]);
	}

	cout<<ans;

	return 0;
}