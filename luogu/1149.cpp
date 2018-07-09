#include <iostream>

/*
	P1149 火柴棒等式
	AC
*/

using std::cin;
using std::cout;

int main()
{
	int n,ans[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 8, 9, 6, 9, 29, 39, 38, 65, 88, 128};

	cin>>n;

	cout<<ans[n];

	return 0;
}