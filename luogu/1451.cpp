/*
	P1451 求细胞数量
*/
#include <iostream>
#include <utility>
#include <queue>

using std::cin;
using std::cout;
using std::pair;
using std::queue;
using std::make_pair;

const int MAXNM = 105;

int
	M,N,ans,
	vis[MAXNM][MAXNM],
	dx[4]	= {-1,0,1,0},	dy[4]	= {0,-1,0,1},
	ddx[4]	= {-1,1,1,-1},	ddy[4]	= {0,-1,1,1};

char map[MAXNM][MAXNM];
queue<pair<int,int>> quq;

int main()
{
	int x,y,xx,yy;
	char ch;

	cin>>M>>N;
	cin.getline(map[1] + 1,90);
	for(int i = 1;i <= M;++i)
		cin.getline(map[i] + 1,N + 5);

	for(int i = 1;i <= M;++i)
	{
		for(int j = 1;j <= N;++j)
		{
			if(map[i][j] == '0' || vis[i][j])
				continue;

			quq.push(make_pair(i,j));
			vis[i][j] = ++ans;//new color (not necessary)

			while(!quq.empty())
			{
				x = quq.front().first;
				y = quq.front().second;

				quq.pop();

				for(int i = 0;i < 4;++i)
				{
					xx = x + dx[i];
					yy = y + dy[i];

					if(!xx || !yy || xx > M || yy > N)
						continue;

					if(map[i][j] == '0' || vis[i][j])
						continue;

					quq.push(make_pair(xx,yy));
					vis[i][j] = ans;
				}
			}
		}
	}

	cout<<ans;

	return 0;
}