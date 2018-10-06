/*
	P1805 关灯
*/
#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 1010,MAXBIT = 1000;

int n;
struct hint
{
	char val[MAXBIT];
	int index;

	void mul2()
	{
		for(int i = 0,car = 0;i <= index;++i)
		{
			val[i] <<= 1;
			val[i] += car;
			car = val[i] / 10;
			val[i] %= 10;
		}
		if(val[index])
			++index;
	}

	hint min1()
	{
		hint res = *this;
		for(int i = 0,car = 0;i < res.index;++i)
		{
			--res.val[i];
			res.[i] -= car;
			if(res.val[i] < 0)
			{
				res.val[i] += 10;
				car = 1;
			}
			if(!car)
				break;
		}
	}

	hint operator-(const hint &a)
	{
		int res = *this;
		unsigned borrow = 0;
		for(int i = 0;i < index;++i)
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
		return res;
	}

	friend std::ostream& operator<<(std::ostream &out,const hint &a)
	{
		for(int i = a.index - 1;i > -1;--i)
			out.put(a.val[i] + '0');
		return out;
	}
}
f,
pows;//2^n

inline void minus()
{
	pows.min1();
	f = pows - f;
}

int main()
{
	int N,light;
	pows.val[0] = 1;//2^0
	pows.index = f.index = 1;

	cin>>N;
	for(int i = 1;i <= N;++i)
	{
		cin>>light;
		//if light
		//	f[n]=2^n-1-f[n-1]
		//else
		//	f[n] = f[n - 1]
		if(light)
		{
			while((++n) <= a)
				pows.mul2();
			--n;
			minus();//-1-f[n-1]
		}
	}

}