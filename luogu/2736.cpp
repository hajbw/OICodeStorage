/**
	P2736 “破锣摇滚”乐队 Raucous Rockers
	AC
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAXNUM = 22;

int
	time_[MAXNUM],
	dp[MAXNUM][MAXNUM];//max-song[disc][used-time]

inline void maximize(int &a,const int &b,const int &c)
{
	if(b > a)a = b;
	if(c > a)a = c;
}

int main()
{
	int N,T,M;

	cin>>N>>T>>M;
	for(int i = 0;i < N;++i)
		cin>>time_[i];

	for(int i = 0;i < N;++i)				//for each song
		for(int j = M;j > 0;--j)			//for each disc
			for(int k = T;k >= time_[i];--k)//for time
				maximize
				(
					dp[j][k],
					dp[j - 1][T] + 1,
					dp[j][k - time_[i]] + 1
				);

	cout<<dp[M][T];

	return 0;
}
