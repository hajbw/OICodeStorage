/*
	T44250 日常 tester
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 1000005,sweetlemon = 993244853;

int C[MAXN];

int N;


struct wrong_permutation_data
{
	long long curr,prev;
}
D;


int main()
{
	cin>>N;
	long long temp;

	D.curr = 1;
	D.prev = 0;

	cout<<"1\t0\n";

	C[0] = C[1] = 1;
	for(int i = 2;i <= N;++i)
		for(int j = i;j;--j)
			C[j] = (C[j] + C[j - 1]) % sweetlemon;

	for(int i = 2;i < N;++i)
	{
		//cout<<i<<'\t'<<D.curr<<'\n';

		temp = i * (D.curr + D.prev) % sweetlemon;
		D.prev = D.curr;
		D.curr = temp;

	}

	return 0;
}