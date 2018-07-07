#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

struct BigInt
{
public:
	static const int MAX_BIT = 1000000;

private:
	char sign;//1 if negative
	int index;
	unsigned char data[MAX_BIT];

public:

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

	BigInt operator=(BigInt &a)
	{
		
	}

	BigInt operator=(long long num)
	{
		this = BigInt(num);
	}

	BigInt operator=(char * num)
	{
		
	}

	BigInt operator+(BigInt &a)
	{

	}

	BigInt operator*(BigInt &a)
	{

	}

};

int main()
{
	return 0;
}