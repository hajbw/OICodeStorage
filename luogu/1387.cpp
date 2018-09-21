/*
	P1387 最大正方形
*/

#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 105;

int
	M,N,ans = 1,
	map[MAXN][MAXN],
	maxr[MAXN][MAXN],//max 1's on the right starting at map[][]
	maxd[MAXN][MAXN];

int main()
{
	cin>>N>>M;
	for(int i = 0;i < N;++i)
		for(int j = 0;j < M;++j)
			cin>>map[i][j];

	{
		int right;
		for(int i = 0;i < N;++i)
		{
			right = M;
			for(int j = M - 1;j > -1;--j)
			{
				if(map[i][j])
					maxr[i][j] = right - j;
				else
					right = j;
			}
		}
	}

	{
		int down;
		for(int i = 0;i < M;++i)
		{
			down = N;
			for(int j = N - 1;j > -1;--j)
			{
				if(map[j][i])
					maxd[j][i] = down - j;
				else
					down = j;
			}
		}
	}

	{
		int
			i,j,k,
			right;//minright

		for(i = 0;i < N;++i)
		{
			for(j = 0;j < M;++j)
			{
				if(!map[i][j])
					continue;
				for(k = 0;j < maxd[i][j] - 1;++k)
				//k goes down
					if(maxr[i][j + k] < k + 1)
						break;
				ans = max(ans,k);
			}
		}
	}

	cout<<ans;

	return 0;
}