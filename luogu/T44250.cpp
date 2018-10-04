/*
	T44250 日常
*/
#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 1000005,sweetlemon = 993244853;

struct wrong_permutation_data
{
	long long curr,prev;
}
D;

int C[MAXN];//C(n,k)

//d = C(n,k) * D(k)

int main()
{
	int N,k;//K,d -> ans!!!
	long long ck,dk,d,temp;

	cin>>N;
	//preprocess
	C[0] = C[1] = 1;
	for(int i = 2;i <= N;++i)
		for(int j = i;j;--j)
			C[j] = (C[j] + C[j - 1]) % sweetlemon;
	//D(2) = 1
	D.curr = 1;
	D.prev = 0;

	cin>>ck;//i = 0
	k = 0;
	d = ck;
	if(N >= 1)//i = 1 not exists
		cin>>ck;
	for(int i = 2;i <= N;++i)
	{
		cin>>ck;

		dk = (ck * C[i] % sweetlemon) * D.curr % sweetlemon;

		if(dk > d)
		{
			d = dk;
			k = i;
		}

		//wrong permutations D(i + 1)
		temp = i * (D.curr + D.prev) % sweetlemon;
		D.prev = D.curr;
		D.curr = temp;
	}

	cout<<d<<'\n';

	for(int i = 1;i <= N - k;++i)
		cout<<i<<' ';
	for(int i = N - k + 2;i <= N;++i)
		cout<<i<<' ';
	if(k)
		cout<<N - k + 1;

	return 0;
}