#include <iostream>

/*
	P1028 数的计算
*/

using std::cin;
using std::cout;

int calc(int i)
{
	if(i == 1)
		return 1;
	int sum = 1;
	for (int ii = 1; ii <= i >> 1; ++ii)
		sum += calc(ii);
	return sum;
}

int main()
{
	int n;
	cin>>n;
	cout<<calc(n);
}