#include <iostream>
#include <cstring>

#ifndef max
#define max(a,b) (a > b ? a: b)
#endif

#ifndef min
#define min(a,b) (a < b ? a : b)
#endif

using std::cin;
using std::cout;
using std::ostream;
using std::istream;

struct BigInt
{

	friend std::ostream& operator<<(std::ostream &out,const BigInt &a);
	friend std::istream& operator>>(std::istream &in,BigInt &a);

	int
		sign,//1 if negative
		index;
	unsigned char data[MAX_BIT];

public:

	static const int MAX_BIT = 1000000;

	BigInt()
	{
		sign = index = 0;
		std::memset(data,0,sizeof(data));
	}

	BigInt(long long num)
	{
		*this = num;
	}

	BigInt(BigInt &a)
	{
		sign = a.sign;
		index = a.index;
		std::memcpy(data,a.data,sizeof(data));
	}

	BigInt(BigInt *a)
	{
		sign = a->sign;
		index = a->index;
		std::memcpy(data,a->data,sizeof(data));
	}

	//operators

	BigInt& operator=(long long num)
	{
		int index = 0;
		if(num < 0ll)
		{
			sign = 1;
			num = -num;
		}
		while(num)
		{
			data[index] = num % 10;
			num /= 10;
			++index;
		}
		this->index = index;

		return *this;
	}

	BigInt& operator+(BigInt &a)
	{
		BigInt res(this);
		res += a;
		return res;
	}

	BigInt operator-(BigInt &a)
	{
		BigInt res(this);
		res -= a;
		return res;
	}

	BigInt& operator*(BigInt &a)
	{
		BigInt res;
		res.sign = this->sign ^ a.sign;
		res.index = this->index + a.index;
		for(int i = 0;i < this->index;++i)
			for(int j = 0;i < a.index;++j)
			{
				res.data[i+j] += data[i] * a.data[j];
				res.data[i+j+1] += res.data[i+j] / 10;
				res.data[i+j] %= res.data[i+j];
			}
		if(!res.data[res.index - 1])
			--index;
		return res;
	}

	void operator+=(BigInt &a)
	{
		index = max(index,a.index) + 1;
		for(int i = 0,x = 0;i < index;++i)
		{
			data[i] = data[i] + a.data[i] + x;
			x = data[i] / 10;
			data[i] %= 10;
		}
		if(!data[index - 1])
			--index;
	}

	void operator-=(BigInt &a)
	{
		*this += -a;
	}

	void operator*=(BigInt &a)
	{
		*this = *this * a;
	}

};

/**
	NOTE:use friend maybe?
*/
std::ostream& operator<<(std::ostream &out,const BigInt &a)
{
	if(a.sign)
		out.put('-');
	for(int i = a.index;i > -1;--i)
		out.put(char(a.data[i] + '0'));
	return out;
}

std::istream& operator>>(std::istream &in,BigInt &a)
{
	a.sign = 0;
	a.index = 0;
	std::memset(a.data,0,sizeof(a.data));

	char ch;

	in.get(ch);
	while(ch < '0' || ch > '9')
	{
		a.sign ^= (ch == '-');
		in.get(ch);
	}
	while(ch >= '0' && ch <= '9')
	{
		a.data[a.index] = ch - '0';
		++a.index;
		in.get(ch);
	}

	return in;
}

int main()
{
	return 0;
}