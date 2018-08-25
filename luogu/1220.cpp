#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
	P1220 关路灯
*/

using std::cin;
using std::cout;

const int MAXN = 55,;

int
	power[MAXN],power_sum[MAXN],pos[MAXN],
	dp[MAXN][MAXN][2];//least-used-power[lbound][rbound][left/right]


template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

int main()
{
	int N,C;

	read(N);read(C);
	read(pos[0]);read(power[0]);
	power_sum[0] = power[0];
	for(int i = 1;i < N;++i)
	{
		read(pos[i]);read(power[i]);
		power_sum[i] = power_sum[i - 1] + power[i];
	}



	return 0;
}