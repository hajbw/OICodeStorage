#include <iostream>

/*
	P1164 小A点菜
	AC
*/

using std::cin;
using std::cout;

const int MAXM = 10010,MAXN = 101;

int a[MAXN],c[MAXM] = {1};

int main()
{
	int M,N,i,j;

	cin>>N>>M;

	for (i = 0; i < N; ++i)
		cin>>a[i];

	for (i = 0; i < N; ++i)
		for(j = M - a[i];j >= 0;--j)
			c[j + a[i]] += c[j];

	cout<<c[M];

	return 0;
}