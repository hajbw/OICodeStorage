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
//public:
	static const int MAX_BIT = 1000000;

//private:
	int sign;//1 if negative
	int index;
	unsigned char data[MAX_BIT];

//public:

	//constructors

	BigInt()
	{
		sign = index = 0;
		std::memset(data,0,sizeof(data));
	}

	BigInt(long long num)
	{
		int index = 0;
		if(num < 0ll)
		{
			sign = 1;
			num = ~num + 1;
		}
		while(num)
		{
			data[index] = num % 10;
			num /= 10;
			++index;
		}
		this->index = index;
	}

	BigInt(BigInt &a)
	{
		sign = a.sign;
		index = a.index;
		std::memcpy(data,a.data,sizeof(data));
	}

	//operators

	void operator=(long long num)
	{
		*this = BigInt(num);
	}

	BigInt operator+(BigInt &a)
	{
		BigInt res = *this;
		res += a;
		return res;
	}

	/*BigInt operator-(BigInt &a)
	{
		BigInt res = *this;
		res -= a;
		return res;
	}*/

	/*BigInt operator-()
	{
		BigInt res = *this;
		res.sign = !res.sign;
		return res;
	}*/

	BigInt operator*(BigInt &a)
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

	/*void operator-=(BigInt &a)
	{
		*this += -a;
	}*/

	void operator*=(BigInt &a)
	{
		*this = *this * a;
	}

	//functions

	/*int size()
	{
		return index;
	}*/

};

ostream& operator<<(ostream &out,const BigInt &a)
{
	if(a.sign)
		out.put('-');
	for(int i = a.index;i > -1;--i)
		out.put(char(a.data[i] + '0'));
	return out;
}

istream& operator>>(istream &in,BigInt &a)
{
	a.sign = 0;
	a.index = 0;
	std::memset(a.data,0,sizeof(a.data));

	char ch;

	in.get(ch);
	while(ch < '0' || ch > '9')
	{
		a.sign |= (ch == '-');
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
	std::ios::sync_with_stdio(false);

	BigInt x,y;
	int operation;

	while(cin>>x>>operation>>y)
	{
		switch(operation)
		{
			case 1:
				cout<<x+y;
				break;
			case 2:
				cout<<x-y;
		}
	}

	return 0;
}