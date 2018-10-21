/*
	P1219 八皇后
	AC
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
//b[x - y]
//c[x + y]

void dfs(int x)
{
	if(x > N)
	{
		++ans;
		if(ans > 3)
			return;
		for(int i = 1;i <= N;++i)
			cout<<stat[i]<<' ';
		cout<<'\n';
		return;
	}

	for(int y = 1;y <= N;++y)
	{
		if(a[y] || b[x - y] || c[x + y])
			continue;
		stat[x] = y;
		a[y] = b[x - y] = c[x + y] = 1;
		dfs(x + 1);
		a[y] = b[x - y] = c[x + y] = 0;
	}
}

int main()
{
	cin>>N;

	dfs(1);

	cout<<ans;

	return 0;
}