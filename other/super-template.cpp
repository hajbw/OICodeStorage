/**
	hajbw super template
*/

//fast read

#ifndef _IOSTREAM_
#include <iostream>
#endif

using std::cin;

#ifndef MAX_LINE_LENGTH
#define MAX_LINE_LENGTH 40
#endif

//version 1:read three

char buf[MAX_LINE_LENGTH];
template<class T> void read(T &x,T &y,T &z)
{
	x = y = z = 0;

	char *ptr = buf;
	cin.getline(buf,MAX_LINE_LENGTH);
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
	cin.getline(buf,MAX_LINE_LENGTH);
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
