#include <iostream>
#include <cstring>

#define DEBUG 0

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
	P1002 过河卒
	char[] high precision ver.


	+----->
	|    y
	|
	v x

	AC
*/

using std::cin;
using std::cout;

const int MAXN = 24,MAXM = 24,MAXBIT = 50;

struct hint
/**
	fuck high precisions.
*/
{
	char ch[MAXBIT];
	int index;//first that doesn't exist aka. index - 1 exist

	hint():ch(),index(0){}
	hint(const int &a){*this = a;}

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

	hint& operator+=(const hint &a)
	{
		char car = 0;
		if(a.index > index)
			index = a.index;
		for(int i = 0;i <= index;++i)
		{
			ch[i] += a.ch[i] + car;
			car = ch[i] / 10;
			ch[i] %= 10;
		}
		if(ch[index])
			++index;
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
int ctrl[MAXN][MAXN];//1 if controlled by horse

int main()
{
	int M,N,horse_x,horse_y;

	cin>>N>>M>>horse_x>>horse_y;

	{
		ctrl[horse_x][horse_y] = ctrl[horse_x + 1][horse_y + 2] = ctrl[horse_x + 2][horse_y + 1] = 1;
		if(horse_y >= 1)
		{
			ctrl[horse_x + 2][horse_y - 1] = 1;
			if(horse_x >= 2)
				ctrl[horse_x - 2][horse_y - 1] = 1;

			if(horse_y >= 2)
			{
				ctrl[horse_x + 1][horse_y - 2] = 1;
				if(horse_x >= 1)
					ctrl[horse_x - 1][horse_y - 2] = 1;
			}
		}
		if(horse_x >= 1)
		{
			ctrl[horse_x - 1][horse_y + 2] = 1;
			if(horse_x >= 2)
				ctrl[horse_x - 2][horse_y + 1] = 1;
		}
	}

#if DEBUG
	for(int i = 0;i <= N;++i)
	{
		for(int j = 0;j <= M;++j)
			cout<<ctrl[i][j];
		cout.put('\n');
	}
#endif

	for(int i = 0;i <= N && !ctrl[i][0];++i)
		f[i][0] = 1;

	for(int i = 1;i <= M && !ctrl[0][i];++i)
		f[0][i] = 1;

	for(int i = 1;i <= N;++i)
	{
		for(int j = 1;j <= M;++j)
		{
			if(ctrl[i][j])
				continue;
			f[i][j] += f[i][j - 1];
			f[i][j] += f[i - 1][j];
		}
	}

#if DEBUG

	for(int i = 0;i <= N;++i)
	{
		for(int j = 0;j <= M;++j)
			cout<<'|'<<f[i][j]<<'\t';
		cout.put('\n');
	}

#else

	cout<<f[N][M];

#endif

	return 0;
}