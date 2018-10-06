/*
	CF678A Johny Likes Numbers
	AC
*/
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	long long n,k,x;

	cin>>n>>k;

	x = n / k * k;

	while(x <= n)
		x += k;

	cout<<x;

	return 0;

}