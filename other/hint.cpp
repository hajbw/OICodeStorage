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
#define BIT_BASE 100000000
#define _64BIT
#else
#define BIT_PER_INT 4//for 32-bit system
#define BIT_BASE 10000
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
			data[index++] = a % BIT_BASE;
			a /= BIT_BASE;
		}

		return *this;
	}

	//end operator with integer types

	//operator with hint

	hint operator*(hint &a)
	{
		hint res = 0;
		int car;
		for(int i = 0;i < index;++i)
		{
			for(int j = 0;j < a.index;++j)
			{
				res.data[i + j] += data[i] * a.data[j];
				car = res.data[i + j] / BIT_BASE;
				res.data[i + j] %= BIT_BASE;
			}
		}
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
			carry = data[i] / BIT_BASE;
			data[i] %= BIT_BASE;
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
			char chr;
			node *next;

			node():chr(),next(){}
			node(char &chr,node *&next):chr(chr),next(next){}
		}
		*head,*tempnode;
		char ch = '\0';
		int len,data_len,data_xtra,temp;

		a = 0;//clean a

		while((ch < '0' || ch > '9') && in.good())
		{
			a.sign ^= (ch == '-');
			in.get(ch);
		}
		while(ch >= '0' && ch <= '9' && in.good())
		{
			head = new node(ch,head);
			++len;
			in.get(ch);
		}

		data_len = len / BIT_PER_INT - 1;
		data_xtra = len % BIT_PER_INT;

		temp = 0;
		for(int i = data_xtra;i > 0;++i)
		{
			temp = (temp<<1) + (temp<<3) + head->chr - '0';
			tempnode = head;
			head = head->next;
			delete tempnode;
		}
		a.data[data_len + 1] = temp;

		for(int i = data_len;i >= 0;--i)
		{
			temp = 0;
			for(int j = 5;j;--j)
			{
				temp = (temp<<1) + (temp<<3) + head->chr - '0';
				tempnode = head;
				head = head->next;
				delete tempnode;
			}
			a.data[i] = temp;
		}

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
