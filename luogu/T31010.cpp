#include <iostream>
#include <cmath>

/**
	T31010 周哥的直径
*/

using std::cin;
using std::cout;
using std::sqrt;

inline bool isPrime(long long n)
{
	for(long long i = 2ll;i <= sqrt(n);++i)
		if(n % i)
			return true;
	return false;
}

int main()
{
	long long n;

	cin>>n;

	if(isPrime(n))
		cout<<2;
	else
	{

	}

	return 0;
}