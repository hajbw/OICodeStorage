/*
	P1082 同余方程
	AC
*/
#include <iostream>

using std::cin;
using std::cout;

template<class T> T hpow(T a,T n,const T &p)
{
	T res = 1;
	while(n)
	{
		if(n & 1)
			res = res * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return res;
}

template<class T>T exgcd(T a,T b,T &x,T &y)
{
	if(!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	int q = exgcd(b,a % b,y,x);
	y -= a / b * x;
	return q;
}

int main()
{
	long long a,b,x,y;

	cin>>a>>b;

	exgcd(a,b,x,y);

	cout<<(x + b) % b;

	return 0;
}