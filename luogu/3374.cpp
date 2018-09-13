/*
	P3374 【模板】树状数组 1
*/

#include <iostream>

#define lowbit(x) ((x)&-(x))

using std::cin;
using std::cout;

const int MAXN = 500010,MAXM = 500010;

int arr[MAXN],M,N;

inline void add(int index,const int &value)
{
	while(index <= N)
	{
		arr[index] += value;
		index += lowbit(index);
	}
}

inline int sum(int r)
{
	int ans = 0;
	while(r)
	{
		ans += arr[r];
		r -= lowbit(r);
	}
	return ans;
}

inline int sum(int l,int r)
{
	return sum(r) - sum(l - 1);
}

int main()
{
	int a,b,c;

	cin>>N>>M;

	for(int i = 1;i <= N;++i)
	{
		cin>>a;
		add(i,a);
	}

	for(int i = 0;i < M;++i)
	{
		cin>>a>>b>>c;
		if(a == 1)
			add(b,c);
		else
			cout<<sum(b,c)<<"\n";
	}

	return 0;
}