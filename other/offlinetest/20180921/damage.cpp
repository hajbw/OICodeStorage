/*
	SweepCup2018 Day2
	#2 伤害
*/

#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::string;

const int MAXP = 1005;

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

void extract(const int &k,int &p)
{
	long long base,tbase,cnt;

	for(int i = 2;(tbase = base = hpow((long long)i,(long long)k)) <= p;++i)
	{
		if(p % base)
			continue;
		cnt = 1;
		while(!(p % base))
			base	*= tbase,
			cnt		*= i;
		p /= base	/ tbase;
		p *= cnt	/ i;
	}
}

int main()
{
	string A,B;
	int k,p;

	cin>>k>>p>>A>>B;

	extract(k,p);

	cout<<p;

	/*
	for i = a to b:
	if (!i % p)
	{
		++ans;
	}

	alternavive:

	ans2 = (b - a + 1) / p;

	if(!((b - a) % p) && !(a % p))
		++ans2;

	*/
	
	return 0;
}