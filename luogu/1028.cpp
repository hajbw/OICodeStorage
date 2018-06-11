#include <iostream>

/*
	P1028 数的计算
	AC
*/

using std::cin;
using std::cout;

const int MAXN = 1001;

int ans[MAXN] = {1,1,2,2};

int main()
{
	int n;
	
	cin>>n;

	for(int i = 4;i <= n; i += 2)
		ans[i] = ans[i | 1] = ans[i - 1] + ans[i >> 1];

	cout<<ans[n];

	return 0;
}