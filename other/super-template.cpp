/**
	hajbw super template
*/

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#ifdef min
#undef min
#endif
#define min(a,b) ((a) < (b) ? (a) : (b))

#ifdef max
#undef max
#endif
#define max(a,b) ((a) > (b) ? (a) : (b))

#define maxx(a,b) (if((a) < (b))(a) = (b))
#define minn(a,b) (if((a) > (b))(a) = (b))

template<class T1,class T2>struct hpair
{
	T1 first;
	T2 second;
	hpair():first(),second(){}
	hpair(T1 a):first(a),second(){}
	hpair(T1 a,T2 b):first(a),second(b){}
	bool operator<(hpair &a)
	{
		return 
			this->first = a.first ? 
			this->second < a.second :
			this->first < a.first;
	}
}

//fast read

#ifndef _GLIBCXX_ISTREAM
#include <istream>
#endif

template<class T> void read(std::istream &in,T &x)
/**
	templated normal fast read.
	available.
*/
{
	char ch = '\0';
	int flag = 0;
	x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9')
	{
		flag ^= (ch == '-');
		in.get(ch);
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch-'0');
		in.get(ch);
	}
	if(flag)
		x = -x;
}

template<class T> void read(T &x,std::istream &in = std::cin)
/**
	packed fast read with default argument (cin) for istream &in
*/
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

#ifndef READ_MAX_LINE_LENTH
#define READ_MAX_LINE_LENTH 40
#endif

template<class T>void readline(istream &in,T &x)
{
	static char buf[READ_MAX_LINE_LENTH];
	int flag = 0;
	char *ptr = buf;
	x = 0;
	cin.getline(buf,READ_MAX_LINE_LENTH);
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
		x = -x;
}

template<class T>void read(istream &in,T *x,int n)
/**
	SUPER SUPER GREAT fast fast read.
	debugging.
*/
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
			x[n] = -x[n];
	}
	delete [] buf;
}

namespace surperb_fast_read
/**
	probaby BEST fast read EVER
	usage:
	linefeed() first
	then read(x)
	linefeed() again to get a new line
*/
{

char buf[READ_MAX_LINE_LENTH],*ptr,*temp;

bool linefeed()
/**
	read a new line into buf
*/
{
	ptr = buf;
	return bool(std::cin.getline(buf,READ_MAX_LINE_LENTH));
}

template<class T>bool read(T &x)
{
	int flag;temp = ptr;x = 0;
	while(*ptr < '0' || *ptr > '9' && *ptr){flag ^= (*ptr == '-');++ptr;}
	while(*ptr >= '0' && *ptr <= '9'){x = (x<<1) + (x<<3) + *ptr - '0';++ptr}
	return temp == ptr;
}

}

//end fast read

//normal base for modding(%)
const int P = 19260817;

long long fast_pow(long long a,long long b)
/**
	fast power (long long version).
	return: a ^ b.(it's not a xor b !)
*/
{
	long long result = 1ll;
	while(b)
	{
		if(b & 1ll)
			result *= a;
		a *= a;
		b >>= 1;
	}
	return result;
}

template<class T> T fast_pow(T a,T b)
/**
	fast power (template version).
	return: a ^ b.(it's not a xor b !)
*/
{
	T result = 1;
	while(b)
	{
		if(b % 2)
			result *= a;
		a *= a;
		b /= 2;
	}
	return result;
}

long long fast_pow_mod(long long a,long long b)
/**
	fast power with mod(long long version).
	return: a ^ b % P.(it's not a xor b !)
*/
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

long long inv_mod(long long a)
/**
	inverse.
	inv(a) = a^(p-2) (mod p)
	return: 1 / a % P
*/
{
	return fast_pow_mod(a,P - 2);
}

long long gcd(long long a,long long b)
/**
	GCD(Greatest Common Divisor).
	long long version.
*/
{
	return b ? gcd(b,a % b) : a;
}