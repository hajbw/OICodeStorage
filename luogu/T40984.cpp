#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))
/**
	T40984 Chino的成绩
*/

using std::cin;
using std::cout;

const int MAXN = 101,MAXM = 10010;

int
	M,N,
	a[MAXM][MAXN],
	dp;

template<class T>inline void read(T &x)
{
	char ch;int flag = 0;x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');cin.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';}
	if(flag)x = -x;
}

int main()
{

	read(N);read(M);
	for(int i = 0;i < M;++i)
		for(int j = 0;j < N;++j)
			read(a[i][j]);


	return 0;
}