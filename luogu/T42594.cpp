#include <iostream>

/**
	T42594 秘密商店
*/

using std::cin;
using std::cout;

const int MAXN = 102,MAXX = 100010;

struct good
{
	int price,value,isinf;
}
goods[MAXN];

int dp[MAXX];

int gcd(int &a,int &b)
{
	return b ? gcd(b,a % b) : a;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int N,X,a,b,p,q;

	cin>>N>>X;
	for(int i = 0;i < N;++i)
	{
		cin>>a>>b>>p>>q;

		goods[i] = (good){b,a,gcd(p,q) == 1};

	}
}