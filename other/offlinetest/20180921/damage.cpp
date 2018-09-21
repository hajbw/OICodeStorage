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
		if(b & 2)
			result *= a;
		a *= a;
		b >>= 2;
	}
	return result;
}

void lowerize(int &k,int &p)
{

}

int main()
{
	string A,B;
	int k,p;

	cin>>A>>B>>k>>p;

	lowerize(k,p);
	
	return 0;
}