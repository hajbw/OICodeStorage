#include <iostream>

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
	fuck high precisions.q
*/
{
	char ch[MAXBIT];
	int index;//first that doesn't exist aka. index - 1 exist

	hint():ch(),index(0){}
	hint(int &i):ch(),index(i){}

	hint& operator+=(hint &a)
	{
		char carry = 0;
		for(int i = 0;i < )
	}


}

hint f[MAXN][MAXM];

int main()
{
	int M,N,horse_x,horse_y;

	cin>>N>>M>>horse_x>>horse_y;

	for(i = 0;i < MAXM;++i)
	{

	}

	for(i = 1;i < MAXN;++i)
	{
		for(j = 1;j < MAXM;++j)
		{

		}
	}

	cout<<f[M][N];

	return 0;
}