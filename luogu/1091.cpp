/*
	P1091 合唱队形
*/
#include <algorithm>
#include <iostream>
#include <cstring>

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXN = 105,INF = 2147483647;

int arr[MAXN],N,des[MAXN],K1,K2,*temp,ans = INF;

struct
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

	for(int i = 1;i <= N;++i)//枚举最高的T
	{
		memset(des + 1,0,sizeof(int) * N);

		for(int j = i;j;--j)
			*std::lower_bound(des,des + i,arr[i],rev_cmp) = arr[j];

		K1 = std::lower_bound(des,des + i,0,rev_cmp) - des;

		cout<<i<<'\t';
		for(int i = 1;i <= K1;++i)
			cout<<des[i]<<'\t';
		cout<<'\n';

		memset(des + 1,0,sizeof(int) * N);

		for(int j = i;j <= N;++j)
		{
			temp = std::lower_bound(des,des + j,arr[i],rev_cmp);
			cout<<"modify:\t"<<temp - des<<'\t'<<*temp<<'\t';
			cout<<(temp = arr[j]);
		}

		K2 = std::lower_bound(des,des + N,0,rev_cmp) - des;

		cout<<'\t';
		for(int i = 1;i <= K2;++i)
			cout<<des[i]<<'\t';
		cout<<'\n';

		ans = std::min(ans,N - K1 - K2 + 1);
	}

#if DEBUG

	cout<<N<<'\t'<<K1<<'\t'<<K2<<'\n';

#endif

	cout<<ans;

	return 0;
}