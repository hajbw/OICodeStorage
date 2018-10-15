/*
	P1060 开心的金明
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 30010,MAXM = 30;

struct item
{
	int v,p;

	friend std::istream& operator>>(std::istream &in,item &a)
	{
		return in>>a.v>>a.p;
	}
}
items[MAXM];

int dp[MAXN],M,N;

template<class T>inline T max(const T &a,const T &b)
{
	return a > b ? a : b;
}

int main()
{
	cin>>N>>M;
	for(int i = 1;i <= M;++i)
		cin>>items[i];

	for(int i = 1;i <= M;++i)
		for(int j = N;j >= items[i].v;--j)
			dp[j] = max(dp[j],dp[j - items[i].v] + items[i].v * items[i].p);

	cout<<dp[N];

	return 0;
}