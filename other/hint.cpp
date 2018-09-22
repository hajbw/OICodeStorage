/*
	hajbw big int,a high percision template.
*/

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef _HINT
#define _HINT

#include <climits>
#include <istream>
#include <ostream>

#if (INT_MAX == LLONG_MAX)
#define BIT_PER_INT 8//for 64-bit system
#define _64BIT
#else
#define BIT_PER_INT 4//for 32-bit system
#endif

#ifndef MAX_SIZE
#define MAX_SIZE 1000
#endif

#define MAX_BIT_LENGTH (MAX_SIZE * BIT_PER_INT)

class hint
{
private:

	unsigned int
		sign,				//if *this is a negative
		index,				//how many ints in data[] are used
		data[MAX_SIZE];

public:

	hint():index(),data(){}
	hint(const int &num){*this = num;}
	hint(const long long &num){*this = num;}

	//basic operations

	int size()
	{
		return index - 1;
	}

	int bit_length()
	{
		return (index - 1) * BIT_PER_INT;
	}

	int isNeg()
	{
		return sign;
	}

	//end basic operations

	//operator with integer types

	hint& operator=(long long a)
	{
		//cleaning
		for(int i = 0;i < index;++i)
			data[i] = 0;
		index = sign = 0;

		if(a < 0)
		{
			sign = 1;
			a = -a;
		}
		while(a)
		{
			data[index++] = a | ((1 << BIT_PER_INT + 1) - 1);
			a >>= BIT_PER_INT;
		}

		return *this;
	}

	//end operator with integer types

	//operator with hint

	hint operator*(hint &a)
	{
		hint res = 0;
		return res;
	}

	hint& operator*=(hint &a)
	{
		return *this = *this * a;
	}

	hint& operator+=(hint &a)
	{
		int carry,len = (index > a.index ? index : a.index) + 1;
		for(int i = 0;i < len;++i)
		{
			data[i] += a.data[i] + carry;
			carry = data[i] >> BIT_PER_INT;
			data[i] |= (1 << BIT_PER_INT + 1) - 1;
		}
		return *this;
	}

	hint operator+(hint &a)
	{
		hint res = *this;
		res += a;
		return res;
	}

	//end operator with hint

	//operator with IO

	friend std::istream& operator>>(std::istream &in,hint &a)
	{
		struct node
		{
			char ch;
			node *next;
		}
		*head;
		char ch = '\0';
		int len;

		a = 0;//clean a

		while((ch < '0' || ch > '9') && in.good()){a.sign ^= (ch == '-');in.get(ch);}
		while(ch >= '0' && ch <= '9' && in.good()){}

		return in;
	}

	friend std::ostream& operator<<(std::ostream &out,hint &a)
	{
		if(a.sign)
			out.put('-');
		for(int i = a.index - 1;i > -1;--i)
			out<<a.data[i];
		return out;
	}

	//end operator with IO

};

#endif

int main()
{
	return 0;
}
