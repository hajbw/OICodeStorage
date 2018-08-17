#include <iostream>
#include <queue>

#define DEBUG 1

#if DEBUG
#include <windows.h>
#endif

/**
	P2622 关灯问题II
*/

using std::cin;
using std::cout;
using std::queue;

const int MAXN = 11,MAXM = 101;

struct ipair
{
	int stat,step;
	ipair():stat(),step(){}
	ipair(int a,int b):stat(a),step(b){}
};

int
	M,N,
	lights[MAXM][MAXN],
	vis[1<<MAXN];

template<class T>inline void read(T &x)
{
	char ch = '\0';int flag = 0;x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');cin.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
	if(flag)x = -x;
}

inline int operate(int &stat,int &i)
{
	int ans = stat;
	for(int j = 0;j < N;++j)
	{
		if(lights[i][j] == 1)
			ans |= 1<<j;
		if(lights[i][j] == -1)
			ans &= ~(1<<j);
	}
	return ans;
}

int bfs()
{
	queue<ipair> quq;
	int temp;

	quq.push(ipair((1<<N)-1,0));

	while(!quq.empty())
	{
		if(!quq.front().stat)
			return quq.front().step;

		for(int i = 0;i < M;++i)
		{
			temp = operate(quq.front().stat,i);
			if(!vis[temp])
			{
				quq.push(ipair(temp,quq.front().step+1));
				vis[temp] = 1;
			}
		}

		quq.pop();
	}

	return -1;
}

int main()
{
	int a;

	read(N);read(M);
	for(int i = 0;i < M;++i)
		for(int j = 0;j < N;++j)
			read(a),lights[i][j] = a;

	cout<<bfs();

#if DEBUG
	system("pause");
#endif

	return 0;
}