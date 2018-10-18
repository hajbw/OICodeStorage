/*
	P2324 [SCOI2005]骑士精神
*/
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

const int MAXT = 10,MAXN = 8,N = 5;

//0 -> 1
//1 -> 2
//* -> 0
int map[MAXN][MAXN],T,emp_x,emp_y;
char buf[MAXN];

int main()
{
	cin>>T;
	cin.getline(buf,MAXN);
	while(T--)
	{
		for(int i = 1;i <= N;++i)
		{
			cin.getline(buf,MAXN);
			for(int j = 1;j <= N;++j)
			{
				if(buf[j - 1] >= '0')
					map[i][j] = buf[j - 1] - '0' + 1;
				else
				{	
					emp_x = i;
					emp_y = j;
				}
			}
		}

	}

	return 0;
}