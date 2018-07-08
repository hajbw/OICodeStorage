#include <iostream>

/*
	P1414 又是毕业季II
*/

using std::cin;
using std::cout;

const int MAXN = 10001;

int ability[MAXN];

int main()
{
	int n;

	cin>>n;

	for(int i = n - 1;i >= 0;--i)
		cin>>ability[i];

	return 0;
}