#include <iostream>

/**
	U34202 JerryC Loves Driving
	55
*/

using std::cin;
using std::cout;

int main()
{
	int A,B,sum = 0;

	cin>>A>>B;

	for(int i = A;i <= B;++i)
		for(int j = 1;j <= i;++j)
			sum += (j % 2) ? -(i / j) : (i / j);

	cout<<sum;

	return 0;
}