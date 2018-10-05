/*
	T48275 无穷的序列(seq)
*/
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

const int MAXL = 11;

char buf[MAXL],*ch;

inline bool verify(int x)
//test if x = (n * n + n) / 2 + 1 , n in N
//set k = 2(x - 1)
// n ^ 2 + n - k = 0
//delta = 1 + 4k
//delta in N ^ 2 => true
//that res == sqrt(1 + 8(x - 1)) in N
{
	int a,b = (x - 1) << 3 | 1;
	a = sqrt(b);
	return b == a * a;
}

template<class T>void read(T &x)
{
	x = 0;
	cin.getline(buf,MAXL);
	ch = buf;
	while((*ch < '0' || *ch > '9') && *ch)++ch;
	while(*ch >= '0' && *ch <= '9'){x = (x<<3) + (x<<1) + *ch - '0';++ch;}
}

int main()
{
	int n,a;

	read(n);

	//for(int i = 0;i < n;++i)
	while(n--)
	{
		read(a);
		cout<<verify(a)<<'\n';
	}

	return 0;
}