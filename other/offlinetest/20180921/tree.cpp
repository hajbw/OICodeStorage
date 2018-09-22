/*
	SweepCup2018 Day2
	#3 校门内的树
*/

#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 100010,P = 998244353;

int h[MAXN];

template<class T>T gcd(const T &a,const T &b)
{
	return b ? gcd(b,a % b) : a;
}

long long query(const long long &u,const long long &v)
{
	long long ans = 1;
	for(int i = u;i < v;++i)
	{
		for(int j = i + 1;j <= v;++j)
		{
			ans *= gcd(h[i],h[j]);
			ans %= P;
		}
	}
	return ans;
}

int main()
{
	int n,q,u,v;

	cin>>n>>q;
	for(int i = 1;i <= n;++i)
		cin>>h[i];
	for(int i = 0;i < q;++i)
	{
		cin>>u>>v;
		cout<<query(u,v)<<'\n';
	}

	return 0;
}