#include <iostream>

/*
	#16. 第一类斯特林数
*/

using std::cin;
using std::cout;

typedef unsigned long num;

const int mo = 10000007;//ha

num stirling1(num m,num n)
{
	if(m == n)
		return 1;
	if(n == 0)
		return 1;
	if(m == 0)
		return 0;
	return (stirling1(m - 1,n - 1) % mo + stirling1(m,n - 1) * (n - 1) % mo) % mo;
}

int main()
{
	num m,n;

	cin>>n>>m;

	cout<<stirling1(m,n);

	return 0;
}
