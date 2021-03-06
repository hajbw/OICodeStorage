/*
	P1451 求细胞数量
	AC
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
queue<pair<int,int> > quq;

int main()
{
	int x,y;

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
					x += ddx[i];
					y += ddy[i];

					if(!x || !y || x > M || y > N)
						continue;

					if(map[x][y] == '0' || vis[x][y])
						continue;

					quq.push(make_pair(x,y));
					vis[x][y] = ans;
				}
			}
		}
	}

	/*for(int i = 1;i <= M;++i)
	{
		for(int j = 1;j <= N;++j)
			cout<<vis[i][j];
		cout<<'\n';
	}*/

	cout<<ans;

	return 0;
}