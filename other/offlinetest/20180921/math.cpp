/*
	SweepCup2018 Day2
	#1 数学
*/

#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int n;
	long long temp,ans = 0ll;

	cin>>n;
	for(int i = 0;i < n;++i)
	{
		cin>>temp;
		ans += temp - 1ll;
	}

	cout<<ans;

	return 0;
}