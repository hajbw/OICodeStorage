/*
	P1805 关灯
*/
#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 1010;

class hint
{
public:
	static const int MAXL = 100,BIT_PER_INT = 8,BASE = 100000000;

private:

	unsigned int data[MAXL],index;

public:

	hint(){index = 0;}
	hint(const int &n){index = 1,data[0] = n;}

	hint& operator+=(const hint &a)
	{
		int car = 0;
		index = max(index,a.index);
		for(int i = 0;i <= index;++i)
		{
			data[i] += a.data[i] + car;
			car = data[i] / BASE;
			data[i] %= BASE;
		}
		if(data[index])
			++index;
		return *this; 
	}

	hint operator*(const hint &a)
	{
		hint res;
		for(int i = 0;i < index + a.index;++i)
		{
			
		}
	}

	hint& pow2_1(int n)//hint = 2 ^ n - 1
	{

	}
}

int lights[MAXN];
hint f[MAXN];

int main()
{
	int N,light;

	cin>>N;
	for(int i = 1;i <= N;++i)
	{
		cin>>lights[i];
		if(lights[i])
		{
		}
		else
		{
		}
	}

}