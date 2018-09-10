/*
	T45283 古代人的难题( puzzle．pas/c/cpp)
	AC
*/

#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXFIB = 88;

inline long long habs(long long n)
{
	return n < 0 ? -n : n;
}

long long fib[MAXFIB];

void calc_fib()
{
	fib[0] = fib[1] = 1;
	for(int i = 2;i < MAXFIB;++i)
		fib[i] = fib[i - 1] + fib[i - 2];
}

int main()
{
	long long K;
	int l = 0,r = MAXFIB,mid;

	calc_fib();

	cin>>K;

	do
	{
		mid = (l + r) >> 1;
		if(K < fib[mid])
			r = mid;
		else if(K > fib[mid + 1])
			l = mid;
		else
			break;
	}
	while(l != r);

	cout<<fib[mid]<<" "<<fib[mid - 1];

	return 0;
}