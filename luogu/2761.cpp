/*
	P2761 软件补丁问题
*/
#include <iostream>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;

struct hpair
{
	int x,y;

	hpair(const int &x,const int &y):x(x),y(y){}

	bool operator<(const hpair &a)const
	{
		return x < a.x;
	}
};

const int MAXN = 20,MAXM = 105;

//note:
//	patch[index][type]:
//	type:
//		0	=> time
//		1,2	=> B1,B2
//		3,4	=> F1,F2
int	N,M,patch[MAXM][5],vis[1 << MAXN];
char buf[2][MAXN];

int main()
{
	std::priority_queue<hpair> quq;

	cin>>N>>M;

	for(register int i = 0;i < M;++i)
	{
		cin>>patch[i][0]>>buf[0]>>buf[1];
		for(register int t = 0;t < 2;++t)
		{
			for(register int j = 0;j < N;++j)
			{
				switch(buf[t][j])
				{
					case '-':
						patch[i][1 + (t<<1)] |= 1 << j;
					break;
					case '+':
						patch[i][2 + (t<<1)] |= 1 << j;
				}
			}
		}
	}

	std::memset(vis,0x7f,sizeof(vis));

	quq.push(0,(1 << N) - 1);

	while(!quq.empty())
	{
		register hpair u = quq.top();
		quq.pop();

		vis[u.y] = u.x;

		for(register int i = 0,stat,dist;i < M;++i)
		{
			if(
				u.y & patch[i][1] == patch[i][1] &&
				!(u.y & patch[i][2]) &&
				vis[stat = u.y & (~patch[i][3]) | patch[i][4]] > (dist = u.x + patch[i][0])
			)
			{
				vis[stat] = dist;
				quq.push(hpair(dist,stat));
			}
		}
	}

	cout<<vis[0];

	return 0;
}