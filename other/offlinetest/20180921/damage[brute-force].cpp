/*
	SweepCup2018 Day2
	#2 伤害
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

template<class T>T hpow(T a,T b)
{
	T result(1);
	while(b)
	{
		if(b & 1)
			result *= a;
		a *= a;
		b >>= 1;
	}
	return result;
}

int main()
{
	long long A,B;
	long long k,p;
	long long ans;

	cin>>k>>p>>A>>B;

	for(long long i = A;i <= B;++i)
	{
		if(!(hpow(i,k) % p))
			++ans;
	}

	cout<<ans;

	return 0;
}