/*
	P1141 01迷宫
	AC
*/
#include <iostream>
#include <queue>

#define DEBUG 0

using std::cin;
using std::cout;
using std::pair;
using std::queue;
using std::make_pair;

const int MAXN = 1005,MAXM = 100005;

struct hpair
{
	int x,y;

	hpair():x(),y(){}
	hpair(int x,int y):x(x),y(y){}
};

int
	map[MAXN][MAXN],M,N,
	dx[] = {-1,1,0,0},dy[] = {0,0,-1,1},
	shade[MAXN][MAXN],shader,
	ans[MAXN * MAXN];//ans per color

char buf[MAXN];

int bfs(int x,int y)
{
	if(shade[x][y])
		return ans[shade[x][y]];

	queue<hpair> quq;
	hpair a,b;

	++shader;

	shade[x][y] = shader;
	++ans[shader];
	quq.push(hpair(x,y));

	while(!quq.empty())
	{
		a = quq.front();
		quq.pop();

		for(int i = 0;i < 4;++i)
		{
			b = hpair(a.x + dx[i],a.y + dy[i]);
			//cout<<"b:\t"<<b.x<<"\t"<<b.y<<'\n';
			if(!shade[b.x][b.y] && b.x > 0 && b.x <= N && b.y > 0 && b.y <= N && map[a.x][a.y] ^ map[b.x][b.y])
			{
				shade[b.x][b.y] = shader;
				++ans[shader];
				quq.push(b);
			}
		}
	}

	return ans[shader];
}

int main()
{
	int x,y;

	cin>>N>>M;

	cin.getline(buf,MAXN);
	for(int i = 1;i <= N;++i)
	{
		cin.getline(buf,MAXN);
		for(int j = 1;j <= N;++j)
			map[i][j] = buf[j - 1] - '0';
	}

#if DEBUG

	for(int i = 0;i < M;++i)
	{
		cin>>x>>y;
		cout<<bfs(x,y)<<'\t'<<shade[x][y]<<'\t'<<shader<<'\n';
	}

#else

	for(int i = 0;i < M;++i)
	{
		cin>>x>>y;
		cout<<bfs(x,y)<<'\n';
	}

#endif

	return 0;
}