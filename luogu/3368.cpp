/*
	P3368 【模板】树状数组 2
*/
#include <iostream>

#define lowbit(x) ((x)&-(x))

using std::cin;
using std::cout;

typedef long long num_t;

const int MAXN = 500010,MAXM = 500010;

num_t diff[MAXN];
int N,M;

inline void add(num_t i,const int &v)
{
	while(i <= N)
	{
		diff[i] += v;
		i += lowbit(i);
	}
}

inline num_t sum(int r)
{
	num_t res = 0;
	while(r)
	{
		ans += diff[r];
		r -= lowbit(r);
	}
	return res;
}

int main()
{
	num_t curr,prev = 0;
	cin>>N>>M;
	for(int i = 0;i < N;++i)
	{
		cin>>curr;
		add(i,curr - prev);
		curr = prev;
	}
}