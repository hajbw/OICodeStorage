/*
	P3031 [USACO11NOV]高于中位数Above the Median
*/
#include <iostream>

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXN = 100010;

int
	h[MAXN],
	larger[MAXN],larger_,smaller[MAXN],smaller_,smaller_diff[MAXN],
	N,X;

long long ans;

int main()
{
	cin>>N>>X;
	for(int i = 1;i <= N;++i)
	{
		cin>>h[i];

		if(h[i] < X)
		{
			++smaller_;
			smaller_diff[i] = 1;
		}
		else
			++larger_;//also count when h[i] == X

		smaller[i]	= smaller_;
		larger[i]	= larger_;
	}

	for(int i = 1;i <= N;++i)
		

}