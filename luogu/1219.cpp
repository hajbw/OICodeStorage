/*
	P1219 八皇后
*/

#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 16;

int
	N,
	a[MAXN],b_[MAXN<<1],*b = b_ + MAXN,c[MAXN<<1],
	stat[MAXN],ans;

//note:
//a[y]
//b[x + y]
//

void dfs(int x)
{
	if(x >= N)
	{
		++ans;
		if(ans < 4)
		{
			for(int i = 1;i <= N;++i)
				cout<<stat[i]<<' ';
		}
		cout<<'\n';
		return;
	}

	for(int i = 1;i <= N;++i)
	{
		cout<<x<<'\t'<<i<<'\n';
		if(!a[i] && !b[x - i] && !c[x + i])
		{
			cout<<"-";
			a[i] = b[x - i] = c[x + i] = 1;
			stat[i] = x;
			dfs(x + 1);
		}
	}
}

int main()
{
	cin>>N;

	dfs(1);

	cout<<ans;

	return 0;
}