/*
	P3865 【模板】ST表
	AC
*/
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

const int MAXN = 100010,MAXM = 1000010;

int lg2[MAXN],sparse[MAXN][20],arr[MAXN],N,M;

template<class T> inline const T& max(const T &a,const T &b){return a > b ? a : b;}

int main()
{
	std::ios::sync_with_stdio(false);

	cin.tie(NULL);

	cin>>N>>M;
	for(int i = 1;i <= N;++i)
		cin>>sparse[i][0];

	lg2[2] = 1;
	for(int i = 3;i <= N;++i)
		lg2[i] = lg2[(i >> 1)] + 1;

	for(int i = 0;1 << i <= N;++i)
		for(int j = 1;j + (1 << i) <= N;++j)
			sparse[j][i + 1] = max(sparse[j][i],sparse[j + (1 << i)][i]);

	for(int i = 1,l,r,range;i <= M;++i)
	{
		cin>>l>>r;
		range = lg2[r - l + 1];
		//cout<<sparse[l][range]<<'\t'<<sparse[r - (1 << range) + 1][range]<<'\n';
		cout<<max(sparse[l][range],sparse[r - (1 << range) + 1][range])<<'\n';
	}

	return 0;
}