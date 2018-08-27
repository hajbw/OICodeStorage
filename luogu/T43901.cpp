#include <iostream>

/**
	T43901 种树（trees.pas/c/cpp）
*/

using std::cin;
using std::cout;

const int P = 1000;

template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9')in.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
}

int fast_pow_mod(int a,int b)
{
	int result = 1;
	while(b)
	{
		if(b & 1)
			result = result * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return result;
}

int main()
{
	int K,X;

	read(K);read(X);

	return 0;
}