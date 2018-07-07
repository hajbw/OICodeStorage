#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::ostream;
using std::istream;

struct BigInt
{
//public:
	static const int MAX_BIT = 1000000;

//private:
	char sign;//1 if negative
	int index;
	unsigned char data[MAX_BIT];

//public:

	//constructors

	BigInt()
	{
		index = 0;
		std::memset(data,0,sizeof(data));
	}

	BigInt(long long num)
	{
		BigInt();
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
		this.index = index;
	}

	//operators

	BigInt operator=(BigInt &a)
	{
		this.sign = a.sign;
		this.index = a.index;
		std::memcpy(this.data,a.data,sizeof(char) * (index));
	}

	BigInt operator=(long long num)
	{
		this = BigInt(num);
	}

	BigInt operator+(BigInt &a)
	{

	}

	BigInt operator*(BigInt &a)
	{

	}

	//functions

	int size()
	{
		return index;
	}

};

ostream& operator<<(ostream &out,const BigInt &a)
{
	if(a.sign)
		cout<<'-';
	for(int i = a.index;i > -1;--i)
		cout<<a
}

int main()
{
	return 0;
}