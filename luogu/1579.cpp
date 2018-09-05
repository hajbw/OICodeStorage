/**
	P1579 哥德巴赫猜想（升级版）
*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::sqrt;

bool is_prime(const int &a)
{
	if(a < 4)
		return true;
	for(int i = 2,n = sqrt(a);i < n;++i)
		if(a % i)
			return false;
	return true;

}