/*
	P1052 过河
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXL = 1000000009,MAXM = 105;

int main()
{
	int	L,S,T,M;

	cin>>L>>S>>T>>M;
	if(S == T)
	{
		int stone,ans = 0;
		for(int i = 0;i < M;++i)
		{
			cin>>stone;
			ans += !(stone % S);
		}
		cout<<ans;
	}
	else
	{
		int
			stone[MAXM] = {},
			diff[MAXM] = {},
			dp[MAXM] = {},

		for(int i = 1;i <= M;++i)
		{
			cin>>stone[i];
			diff[i] = stone[i] - stone[i - 1];
		}
	}

	return 0;
}