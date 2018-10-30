#include <iostream>
#include <algorithm>
#include <cstring>

/*
	P1803 凌乱的yyy
*/

using std::cin;

const int MAXN = 1000000;

struct competition
{
	int a,b;
	competition(int a,int b)
	{
		this.a = a;
		this.b = b;
	}
};

int main()
{
	int n,ai,bi,result = 0;
	competition arr[MAXN];

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>ai>>bi;
		arr[i] = new competition(ai,bi);
	}

	sort(arr,arr+n,
		[](competition a,competition b) -> 
		bool{return (a.bi - a.ai) < (b.bi - a.ai)}
		)；

	//TODO:DP

	cout<<result;

	return 0;
}