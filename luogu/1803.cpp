/*
	P1803 凌乱的yyy / 线段覆盖
*/
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXN = 1000010;

struct hpair
{
	int x,y;

	bool operator<(const hpair &a)const
	{
		return x == a.x ? y < a.y : x < a.x;
	}

	friend std::istream& operator>>(std::istream &in,hpair &a)
	{
		return in>>a.x>>a.y;
	}
}
contests[MAXN];

int dp[MAXN];

int main()
{
	cin>>N;
	for(int i = 1;i <= N;++i)
		cin>>contests[i];

	std::sort(contests + 1,contests + 1 + N);

	for(int i = 1;i <= N;++i)
	{
		dp[contests[i].y] = max(dp[contests[i].y],dp[contests[i].x] + 1);
	}

	cout<<dp[N];

	return 0;
}