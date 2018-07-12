#include <iostream>
#include <cstring>

/**
	P3958 奶酪
*/

using std::cin;
using std::cout;
using std::memset;

const int MAXN = 1005;

struct hole
{
	int x,y,z;
}
holes[MAXN];

int
	T,n,h,r,
	fa[MAXN];

unsigned long long R;

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
	return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) + (a.y-b.y) + (a.z-b.z) * (a.z-b.z) <= R;
}

int main()
{
	scanf("%d",&T);
	for(int i = 0;i < T;++i)
	{
		memset(holes,0,sizeof(holes));
		memset(fa,0,sizeof(fa));
		read(n,h,r);
		R = 4*r*r;
	}
	return 0;
}