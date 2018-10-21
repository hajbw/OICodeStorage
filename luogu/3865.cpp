/*
	P3865 【模板】ST表
*/
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

const int MAXN = 10010,MAXM = 100000;

int lg2[MAXN],sparse[MAXN][16],arr[MAXN],N,M;

template<class T> inline T min(const T &a,const T &b)
{
	return a < b ? a : b;
}

template<class T> inline T max(const T &a,const T &b)
{
	return a > b ? a : b;
}

int main()
{
	cin>>N>>M;
	for(int i = 1;i <= N;++i)
		cin>>sparse[i][0];

	lg2[2] = 1;
	for(int i = 3;i <= N;++i)
		lg2[i] = lg2[i >> 1] + 1;

	for(int i,j = 0,t = 1;t <= N,j < 16;++j,t <<= 1)//t == 1 << j
		for(i = 0;i + (t << 1) <= N;++i)
			sparse[i][j + 1] = max(sparse[i][j],sparse[i + t][j]);

	for(int i = 1,j,l,r;i <= M;++i)
	{
		cin>>l>>r;
		j = lg2[r - l + 1];
		cout<<max(sparse[l][j],sparse[r - (1 << j) + 1][j])<<'\n';
	}

	return 0;
}