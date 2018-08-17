#include <iostream>
#include <queue>

/**
	P2622 关灯问题II
*/

using std::cin;
using std::cout;

const int MAXN = 11,MAXM = 101;

struct ipair
{
	int stat,step;
	ipair():stat(),step(){}
	ipair(int a,int b):stat(a),step(b){}
};

int
	M,N,
	lights[MAXM][MAXN];

template<class T>inline void read(T &x)
{
	char ch = '\0';int flag = 0;x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');cin.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
	if(flag)x = -x;
}

int bfs()
{
	queue<ipair> quq;

	quq.push(ipair((1<<N)-1,0));

	while(!quq.empty())
	{
		for(int i = 0;i < M;++i)
			quq.push(ipair(operate(i),quq.top().step+1));
		quq.pop();
	}
}

int main()
{
	int a;

	read(N);read(M);
	for(int i = 0;i < M;++i)
		for(int j = 0;j < N;++j)
			read(a),lights[i][j] = a;

	cout<<bfs();

	return 0;
}