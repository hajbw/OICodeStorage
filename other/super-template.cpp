/**
	hajbw super template
*/

//basics

// :)
// :(
//unuseful:ignored
#pragma GCC optimize("O2")
#pragma G++ optimize("O2")
#pragma GCC diagnostic warning "-std=c++11"
#pragma G++ diagnostic warning "-std=c++11"

#ifndef min
#define min(a,b) (a < b ? a : b)
#endif

#ifndef max
#define max(a,b) (a > b ? a : b)
#endif

//end basics

//fast read

#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

using std::cin;

#ifndef READ_MAX_LINE_LENTH
#define READ_MAX_LINE_LENTH 40
#endif

//version 1: read one(in one line)

template<class T>void read(T &x)
{
	x = 0;
	char *ptr = buf;
	cin.getline(buf,READ_MAX_LINE_LENTH);
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
}

//version 2:read three

char buf[READ_MAX_LINE_LENTH];
template<class T> void read(T &x,T &y,T &z)
{
	x = y = z = 0;

	char *ptr = buf;
	cin.getline(buf,READ_MAX_LINE_LENTH);
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

//SUPER SUPER GREAT version

template<class T>void read(T **x,int n)
{
	char *ptr = buf;
	cin.getline(buf,READ_MAX_LINE_LENTH);
	int flag = 0;

	for(int i = 0;i < n;++i)
	{
		flag = 0;
		while(*ptr < '0' || *ptr > '9')
		{
			flag ^= (*ptr == '-');
			++ptr;
		}
		while(*ptr >= '0' && *ptr <= '9')
		{
			*(x[n]) = (*(x[n])<<1) + (*(x[n])<<3) + (*ptr-'0')//2*x+8*x+int(*ptr)
			++ptr;
		}
		if(flag)
			*(x[n]) = ~(*(x[n])) + 1;
	}
}

//end fast read
