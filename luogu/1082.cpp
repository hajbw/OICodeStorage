/*
	P1082 同余方程
*/
#include <iostream>

using std::cin;
using std::cout;

template<class T> T hpow(T a,T n,const T &p)
{
	T res = 1;
	while(b)
	{
		if(b & 1)
			res = res * a % p;
		a = a * a % p;
		b >>= 1;
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

template<class T> T hinv(T a,T p)
{
	return hpow(a,p - 2,p);
}

int main()
{
	long long a,b,x,y;

	cin>>a>>b;

	exgcd(a,b,x,y);

	cout<<

	return 0;
}