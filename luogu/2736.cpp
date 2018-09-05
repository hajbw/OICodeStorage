/**
	P2736 “破锣摇滚”乐队 Raucous Rockers
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAXNUM = 22;

int
	time[MAXNUM],
	dp[MAXNUM][MAXNUM];//max-song[disc][used-time]

inline int maximize(int &a,const int &b,const int &c)
{
	cout<<a<<b<<c<<endl;
	if(b > a)a = b;
	if(c > a)a = c;
	return a;
}

int main()
{
	int N,T,M;

	cin>>N>>T>>M;
	for(int i = 0;i < N;++i)
		cin>>time[i];

	for(int i = 0;i < N;++i)				//for each song
		for(int j = M;j > 0;--j)			//for each disc
			for(int k = T;k >= time[i];--j)	//for time
				cout<<i<<j<<k<<endl,maximize
				(
					dp[j][k],
					dp[j - 1][T] + 1,
					dp[j][k - time[i]] + 1
				);

	cout<<dp[M][T];

	return 0;
}
