/*
	P1627 [CQOI2009]中位数
	also T51286 中位数（median.cpp）
	AC
*/
#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 100010;

int N,B,iB,arr[MAXN],f_[MAXN<<1],*f = f_ + MAXN,ans,sum,l,r;

int main()
{
	int a;

	cin>>N>>B;
	for(int i = 1;i <= N;++i)
	{
		cin>>a;
		if(a == B)
			iB = i;
		else
			arr[i] = a < B ? -1 : 1;
	}

	for(int i = iB - 1;i;--i)
	{
		sum += arr[i];
		++f[sum];
	}

	ans += f[0];
	sum = 0;

	for(int i = iB + 1;i <= N;++i)
	{
		sum += arr[i];
		ans += f[-sum];
		if(!sum)
			++ans;
	}

	cout<<ans + 1;

	return 0;
}