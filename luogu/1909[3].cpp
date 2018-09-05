/**
	P1909 买铅笔
	AC
*/

#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n,count,price,ans = 19260817;

	cin>>n;
	for(int i = 0;i < 3;++i)
	{
		cin>>count>>price;

		ans = min(ans,(n + count - 1) / count * price);
	}

	cout<<ans;

	return 0;
}