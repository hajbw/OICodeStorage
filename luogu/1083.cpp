/*
	P1083 借教室
	AC
*/
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

const int MAXM = 1000010,MAXN = 1000010;

long long r[MAXN],d[MAXM],diff[MAXN],sum;
int M,N,s[MAXM],t[MAXM],flag;

inline bool satisfy(int m)
{
	sum = 0;
	std::memset(diff,0,sizeof(long long) * (N + 2));

	for(int i = 1;i <= m;++i)
	{
		diff[s[i]]		+= d[i];
		diff[t[i] + 1]	-= d[i];
	}

	for(int i = 1;i <= N;++i)
	{
		sum += diff[i];
		if(sum > r[i])
			return false;
	}

	return true;
}

int main()
{
	cin>>N>>M;

	for(int i = 1;i <= N;++i)
		cin>>r[i];

	for(int i = 1;i <= M;++i)
		cin>>d[i]>>s[i]>>t[i];

	int lb = 0,rb = M + 1,mid;

	while(rb - lb > 1)
	{
		mid = lb + rb >> 1;

		if(satisfy(mid))
			lb = mid;
		else
			rb = mid;
	}

	if(lb == M)
		cout<<0;
	else
		cout<<"-1\n"<<rb;

	return 0;
}