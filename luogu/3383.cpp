/*
	P3383 【模板】线性筛素数
	AC
*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::sqrt;

bool is_prime(const int &a)
{
	if(a < 2)
		return false;
	if(a < 4)
		return true;
	if(a % 6 != 1 && a % 6 != 5)
		return false;

	int sqrta = sqrt(a);
	for(int i = 5;i <= sqrta;i += 6)
		if(!(a % i && a % (i + 2)))
			return false;

	return true;
}

int main()
{
	int M,N,a;

	cin>>N>>M;

	for(int i = 0;i < M;++i)
	{
		cin>>a;
		cout<<(is_prime(a) ? "Yes\n" : "No\n");
	}

	return 0;
}