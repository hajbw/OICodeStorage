#include <iostream>

/**
	P1464 Function
	AC
*/

using std::cin;
using std::cout;

long long w[22][22][22];

long long dfs(const long long &a,const long long &b,const long long &c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return 1ll;
	if(a > 20 || b > 20 || c > 20)
		return w[20][20][20];

	if(w[a][b][c])
		return w[a][b][c];

	if(a < b && b < c)
		return w[a][b][c] = dfs(a,b,c - 1ll) + dfs(a,b - 1ll,c - 1ll) - dfs(a,b - 1ll,c);

	return w[a][b][c] = dfs(a - 1ll,b,c) + dfs(a - 1ll,b - 1ll,c) + dfs(a - 1ll,b,c - 1ll) - dfs(a - 1ll,b - 1ll,c - 1ll);
}

int main()
{
	std::ios::sync_with_stdio(false);

	long long a,b,c;

	for(int i = 1;i < 21;++i)
		w[i][i][i] = 1<<i;

	while( ~(1 ^ 1) )
	{
		cin>>a>>b>>c;

		if(a == -1 && b == -1 && c == -1)
			break;

		//w(a, b, c) = ans
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dfs(a,b,c)<<"\n";
	}

	return 0;
}