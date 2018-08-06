/**
	hajbw super template
*/

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

#ifndef maxx
#define maxx(a,b) (if(a < b)a = b)
#endif

#ifndef minn
#define minn(a,b) (if(a > b)a = b)
#endif

//end basics

//fast read

#ifndef READ_MAX_LINE_LENTH
#define READ_MAX_LINE_LENTH 40
#endif

char buf[READ_MAX_LINE_LENTH];

//version 1: read one(in one line)

template<class T>void readline(istream &in,T &x)
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
		x = (x<<1) + (x<<3) + (*ptr-'0');//2x+8x+int(*ptr)
		++ptr;
	}
	if(flag)
		x = ~x + 1;
}

//SUPER SUPER GREAT version

template<class T>void read(istream &in,T *x,int n)
{
	char *buf,*ptr;
	buf = ptr = new char[READ_MAX_LINE_LENTH];
	in.getline(buf,READ_MAX_LINE_LENTH);
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
			x[n] = (x[n]<<1) + (x[n]<<3) + (*ptr-'0');//2*x+8*x+int(*ptr)
			++ptr;
		}
		if(flag)
			x[n] = ~x[n] + 1;
	}
	delete [] buf;
}

//end fast read

//fast power

const int P = 19260817;

long long fast_pow(long long a,long long b)
{
	long long result = 1ll;
	while(b)
	{
		if(b & 1ll)
			result = result * a;
		a = a * a;
		b >>= 1;
	}
	return result;
}

long long fast_pow_mod(long long a,long long b)
{
	long long result = 1ll;
	while(b)
	{
		if(b & 1ll)
			result = result * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return result;
}

//inverse

long long inv_mod(long long a)
/**
	inv(a) = a^(p-2) (mod p)
	return : 1 / a % P
*/
{
	return fast_pow_mod(a,P - 2);
}

//gcd

long long gcd(long long a,long long b)
{
	return b ? gcd(b,a % b) : a;
}