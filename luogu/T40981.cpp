#include <iostream>

/**
	T40981 Chino的交通
*/

using std::cin;
using std::cout;

const int MAXN = 100010,P = 998244353;

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

template<class T>inline void read(T &x)
{
	char ch;int flag = 0;x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');cin.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';}
	if(flag)x = -x;
}

int main()
{
	int N,T;

	read(T);
	for(int i = 0;i < T;++i)
	{
		read(N);
	}
}