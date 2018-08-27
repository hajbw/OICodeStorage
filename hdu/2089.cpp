#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
	不要62
*/

using std::cin;
using std::cout;

const int MAXM = 1000000,MAXN = 1000000,MAXBIT = 8;

int
	M,N,bitcount,lastbitcount,
	dp[MAXBIT][10];//sum[bits - 1][first-num]

template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9')in.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
}

inline int countbit(int x)
{
	int ans = 0;
	while(x)
	{
		++ans;
		x /= 10;
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int a,b;//temp variants

	while( ~(1 ^ 1) )
	{
		read(N);read(M);
		if(!N && !M)
			break;

		bitcount = min(countbit(M),countbit(N));

		//pre-processes
		if(bitcount > lastbitcount)
		{
			for(int i = lastbitcount;i < bitcount;++i)
			{
				for(int j = 0;j < 10;++j)
				{

				}
			}
			lastbitcount = bitcount;
		}

	}
}