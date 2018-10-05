/*
	P1601 A+B Problem（高精）
*/
#include <iostream>

using namespace std;

#ifndef _HUINT
#define _HUINT

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif
#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#include <climits>
#include <istream>
#include <ostream>
#include <cstring>
#include <string>

class huint
{
public:

	static const int MAX_SIZE = 1000,BIT_PER_INT = 4,BIT_BASE = 10000;

private:

	unsigned data[MAX_SIZE],index;

public:

	huint()
	{
		std::memset(data,0,sizeof(data));
		index = 1;
	}

	huint(const unsigned long long &a)
	{
		index = MAX_SIZE;
		*this = a;
	}

	huint(const std::string &str)
	{
		index = MAX_SIZE;
		*this = str;		
	}

	huint& operator=(unsigned long long a)
	{
		std::memset(data,0,sizeof(int) * index);
		index = 0;

		while(a)
		{
			data[index++] = a % BIT_BASE;
			a /= BIT_BASE;
		}

		return *this;
	}

	huint& operator=(std::string str)
	{
		std::memset(data,0,sizeof(int) * index);
		
		int temp = 0,leak = str.length() % BIT_PER_INT;
		std::string::iterator it = str.begin();
		index = (str.length() - 1) / BIT_PER_INT + 1;

		if(leak)
		{
			for(int i = leak;i;--i,++it)
				temp = temp * 10 + *it - '0';
			data[index - 1] = temp;
		}

		for(int i = index - 1 - (bool)leak;i > -1;--i)
		{
			temp = 0;
			for(int j = 0;j < 4;++j,++it)
				temp = temp * 10 + *it - '0';
			data[i] = temp;
		}

		return *this;
	}

	huint& operator+=(const huint &a)
	{
		unsigned car = 0;
		index = max(index,a.index);
		for(unsigned i = 0;i < index;++i)
		{
			data[i] += a.data[i] + car;
			car = data[i] / BIT_BASE;
			data[i] %= BIT_BASE;
		}
		if(data[index])
			++index;
		return *this;
	}

	huint operator+(const huint &a)
	{
		huint res = *this;
		res += a;
		return res;
	}

	huint& operator-=(const huint &a)//assume that *this > a => index >= a.index
	{
		unsigned borrow = 0;
		for(unsigned i = 0;i < index;++i)
		{
			if(a.data[i] + borrow > data[i])
			{
				borrow = 1;
				data[i] += BIT_BASE - a.data[i];
			}
			else
				data[i] -= borrow + a.data[i];
			if(i >= a.index && !borrow)
				break;
		}
		return *this;
	}

	huint operator-(const huint &a)
	{
		huint res = *this;
		res -= a;
		return res;
	}

	operator bool()
	{
		return index && data[0];
	}

	bool operator!()
	{
		return index >= 1 && !data[0];
	}

	friend int greater(const huint &a,const huint &b)
	{
		if(a.index - b.index)
			return (a.index - b.index) & INT_MIN ? -1 : 1 ;

		//a.index == b.index
		for(int i = a.index - 1;i > -1;--i)
			if(a.data[i] - b.data[i])
				return (a.data[i] - b.data[i]) & INT_MIN ? -1 : 1;

		return 0;
	}

	friend bool operator==(const huint &a,const huint &b)
	{
		return greater(a,b);
	}

	friend bool operator<(const huint &a,const huint &b)
	{
		return greater(b,a) == 1;
	}

	friend bool operator>(const huint &a,const huint &b)
	{
		return greater(a,b) == 1;
	}

	friend bool operator>=(const huint &a,const huint &b)
	{
		return greater(b,a) != 1;
	}

	friend bool operator<=(const huint &a,const huint &b)
	{
		return greater(a,b) != 1;
	}

	friend std::istream& operator>>(std::istream &in,huint &a)
	{
		std::string str;
		in>>str;
		a = str;
		return in;
	}

	friend std::ostream& operator<<(std::ostream &out,const huint &a)
	{
		cout<<a.data[a.index - 1];
		cout.fill('0');
		cout.width(4);
		for(int i = a.index - 2;i > -1;--i)
			cout<<std::right<<a.data[i];
		return out;
	}
};

#endif

int main()
{
	huint a,b;

	cin>>a>>b;

	cout<<a + b;

	return 0;
}