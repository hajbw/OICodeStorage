/*
	P3368 【模板】树状数组 2
	AC
*/
#include <iostream>

#define lowbit(x) (x&-x)

using std::cin;
using std::cout;

typedef int num_t;

const int MAXN = 500010,MAXM = 500010;

num_t diff[MAXN];
int N,M;

inline void add(int i,const num_t &v)
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
		res += diff[r];
		r -= lowbit(r);
	}
	return res;
}

int main()
{
	num_t curr,prev = 0,k;
	int a,x,y;

	cin>>N>>M;
	
	for(int i = 1;i <= N;++i)
	{
		cin>>curr;
		add(i,curr - prev);
		prev = curr;
	}

	for(int i = 0;i < M;++i)
	{
		cin>>a;

		if(a == 1)
		{
			cin>>x>>y>>k;
			add(x,k);
			add(y + 1,-k);
		}
		else
		{
			cin>>x;
			cout<<sum(x)<<'\n';
		}
	}

	return 0;
}
