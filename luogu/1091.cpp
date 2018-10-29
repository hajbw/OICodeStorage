/*
	P1091 合唱队形
	AC
*/
#include <algorithm>
#include <iostream>
#include <cstring>

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXN = 105,INF = 2147483647;

int arr[MAXN],N,des[MAXN],K1,K2,*temp,ans = INF;

struct cmp
{
	bool operator()(int a,int b)const
	{
		return a > b;
	}
}
rev_cmp;

int main()
{
	des[0] = INF;

	cin>>N;
	for(int i = 1;i <= N;++i)
		cin>>arr[i];

	for(int i = 1;i <= N;++i)
	{
		memset(des + 1,0,sizeof(int) * N);

		for(int j = i;j;--j)
			*std::lower_bound(des,des + i,arr[j],rev_cmp) = arr[j];

		K1 = std::lower_bound(des,des + i,0,rev_cmp) - des;

		while(!des[K1])--K1;

		memset(des + 1,0,sizeof(int) * N);

		for(int j = i;j <= N;++j)
			*std::lower_bound(des,des + j,arr[j],rev_cmp) = arr[j];

		K2 = std::lower_bound(des,des + N,0,rev_cmp) - des;

		while(!des[K2])--K2;

		ans = std::min(ans,N - K1 - K2 + 1);
	}

	cout<<ans;

	return 0;
}