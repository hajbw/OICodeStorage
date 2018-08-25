#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define DEBUG 0

#if DEBUG
#include <windows.h>
#endif

/**
	P1877 [HAOI2012]音量调节
	AC
*/

using std::cin;
using std::cout;

const int MAXN = 52,MAXL = 1005;

int levels[MAXN],reachable[MAXN][MAXL];

void read(int &x)
{
	char ch = '\0';x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
}

int main()
{
	int N,beginlevel,maxlevel,flag = 0;

	read(N);
	read(beginlevel);
	read(maxlevel);
	for(int i = 1;i <= N;++i)
		read(levels[i]);

	reachable[0][beginlevel] = 1;
	for(int i = 1;i <= N && !flag;++i)
	{
		flag = 1;
		for(int j = 0;j <= maxlevel;++j)
		{
			if(reachable[i - 1][j])
			{
				if(j + levels[i] <= maxlevel)	reachable[i][j + levels[i]] = 1;
				if(j >= levels[i])				reachable[i][j - levels[i]] = 1;
				flag = 0;
			}
		}
		if(flag)
			break;
	}

	if(flag)
		cout<<-1;
	else
	{
		int i;
		for(i = maxlevel;i && !reachable[N][i];--i);
		cout<<(i ? i : -1);//quite ugly fix
	}

#if DEBUG
	cout<<"\nflag = "<<flag<<"\n";

	for(int i = 0;i <= N;++i)
	{
		for(int j = 0;j <= maxlevel;++j)
			cout<<reachable[i][j];
		cout<<"\n";
	}

	system("pause");
#endif

	return 0;
}