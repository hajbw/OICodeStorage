/**
	hajbw super template
*/

#ifndef min
#define min(a,b) (a < b ? a : b)
#endif

#ifndef max
#define max(a,b) (a > b ? a : b)
#endif

#ifdef min
#undef min
#endif
#define min(a,b) (a < b ? a : b)

#ifdef max
#undef max
#endif
#define max(a,b) (a > b ? a : b)

#ifndef maxx
#define maxx(a,b) (if(a < b)a = b)
#endif

#ifndef minn
#define minn(a,b) (if(a > b)a = b)
#endif

//end basics

//fast read

template<class T> void read(istream &in,T &x)
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
			x[n] = -x[n];
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
			result *= a;
		a *= a;
		b >>= 1;
	}
	return result;
}

template<class T> T fast_pow(T a,T b)
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