#include <iostream>
#include <cstring>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
	P1002 过河卒
*/

using std::cin;
using std::cout;

const int MAXN = 22,MAXM = 22,MAXBIT = 50;

struct hint
/**
	fuck high precisions.
*/
{
	char ch[MAXBIT];
	int index;//first that doesn't exist aka. index - 1 exist

	hint():ch(),index(0){}

	hint& operator=(int a)
	{
		index = 0;

		while(a)
		{
			ch[index++] = a % 10;
			a /= 10;
		}

		return *this;
	}

	hint& operator+=(hint &a)
	{
		char car = 0;
		for(int i = 0;i <= max(index,a.index);++i)
		{
			ch[i] += a.ch[i] + car;
			car = ch[i] / 10;
			ch[i] %= 10; 
		}
		return *this;
	}
	
	friend std::ostream& operator<<(std::ostream &out,hint &a)
	{
		for(int i = a.index;i;--i)
			out.put(a.ch[i - 1] + '0');
		return out;
	}
};

hint f[MAXN][MAXM];

int main()
{
	int M,N,horse_x,horse_y,i,j;

	cin>>N>>M>>horse_x>>horse_y;

	f[0][0] = 1;

	for(i = 1;i <= MAXM;++i)
	{
		if(!horse_x && horse_y == i)
			break;
		f[0][i] = f[0][i - 1];
	}

	for(i = 1;i <= MAXN;++i)
	{
		if(!horse_y && horse_x == i)
			break;
		f[i][0] = f[i - 1][0];
	}

	for(i = 1;i <= MAXN;++i)
	{
		for(j = 1;j <= MAXM;++j)
		{

		}
	}

	cout<<f[M][N];

	return 0;
}