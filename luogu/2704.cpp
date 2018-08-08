#include <iostream>

/**
	P2704 [NOI2001]炮兵阵地
*/

#define max(a,b) (a > b ? a : b)
#define maxx(a,b) if(a < b)a = b

using std::cin;
using std::cout;

const int MAXM = 10,MAXN = 1010,ABITS_COUNT = 60;

int abits[ABITS_COUNT] = {0,1,2,4,8,9,16,17,18,32,33,34,36,64,65,66,68,72,73,128,129,130,132,136,137,144,145,146,256,257,258,260,264,265,272,273,274,288,289,290,292,512,513,514,516,520,521,528,529,530,544,545,546,548,576,577,578,580,584,585},
	cabits[ABITS_COUNT] = {0,1,1,1,1,2,1,2,2,1,2,2,2,1,2,2,2,2,3,1,2,2,2,2,3,2,3,3,1,2,2,2,2,3,2,3,3,2,3,3,3,1,2,2,2,2,3,2,3,3,2,3,3,3,2,3,3,3,3,4},
	map[MAXN],dp[MAXN][ABITS_COUNT][ABITS_COUNT];
char line[MAXM+5];

void read(int &x)
{
	x = 0;
	cin.getline(line,MAXM+2);
	for(char *ch = line;*ch;++ch)
	{
		x <<= 1;
		x += (*ch == 'P');
	}
}

int main()
{
	int M,N;

	cin>>N>>M;
	cin.getline();
	for(int i = 0;i < N;++i)
		read(map[i]);

	for(int i = 0;i < n;++i)
	{
		for(int j = 0;j < ABITS_COUNT;++j)
		{
			
		}
	}

	return 0;
}