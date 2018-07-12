#include <iostream>

/**
	P3958 奶酪
*/

using std::cin;
using std::cout;

const int MAXN = 1005;

struct hole
{
	int x,y,z;
}
holes[MAXN];

char buf[40];
template<class T> void read(T &x,T &y,T &z)
{
	x = y = z = 0;

	char *ptr = buf;
	cin.getline(buf,40);
	int flag = 0;
	while(*ptr < '0' || *ptr > '9')
	{
		flag ^= (*ptr == '-');
		++ptr;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		x = (x<<1) + (x<<3) + (*ptr-'0')//2x+8x+int(*ptr)
		++ptr;
	}
	if(flag)
		x = ~x + 1;
	flag = 0;
	while(*ptr < '0' || *ptr > '9')
	{
		flag ^= (*ptr == '-');
		++ptr;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		y = (y<<1) + (y<<3) + (*ptr-'0')//2y+8y+int(*ptr)
		++ptr;
	}
	if(flag)
		y = ~y + 1;
	flag = 0;
	while(*ptr < '0' || *ptr > '9')
	{
		flag ^= (*ptr == '-');
		++ptr;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		z = (z<<1) + (z<<3) + (*ptr-'0')//2z+8z+int(*ptr)
		++ptr;
	}
	if(flag)
		z = ~z + 1;
}


inline int touched(hole &a,hole &b)
{

}

int main()
{
	int T,n,h,r;

	scanf("")
	return 0;
}