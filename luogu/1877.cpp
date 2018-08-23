#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
	P1877 [HAOI2012]音量调节
*/

using std::cin;
using std::cout;

const int MAXN = 51,MAXL = 1005;

int levels[MAXN],reachable[MAXL];

void read(int &x)
{
	char ch = '\0';x = 0;
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
}

int main()
{
	int N,beginlevel,maxlevel,flag = 0;

	read(N);read(beginlevel);read(maxlevel);
	for(int i = 0;i < N;++i)
		read(levels[N]);

	reachable[beginlevel] = 1;
	for(int i = 0;i < N && !flag;++i)
	{
		flag = 1;
		for(int j = maxlevel - levels[i];j >= 0;--j)
		{
			if(reachable[j])
				reachable[j + levels[i]] = 1,
				flag = 0;
		}
	}

	if(flag)
		cout<<-1;
	else
	{
		int i;
		for(i = maxlevel;i >= 0 && !reachable[i];--i);
		cout<<i;
	}

	return 0;
}