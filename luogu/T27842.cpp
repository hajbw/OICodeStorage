#include <iostream>
#include <algorithm>
#include <cstring>

/**
	T27842 螺蛳粉
*/

using std::cin;
using std::cout;

const long long MAXN = 100010ll,MAXX = 100010ll;

long long
	N,X,Y,
	ap[MAXN],
	m[MAXX],iminm[MAXX] = {19260817ll};

template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

int main()
{
	std::ios::sync_with_stdio(false);

	long long a,b;

	read(N);read(X);read(Y);
	for(int i = 0;i < N;++i)
	{
		read(a);read(b);
		ap[i] = a * b;
	}
	read(m[0]);
	for(int i = 1;i < X;++i)
	{
		read(m[i]);
		iminm[i] = min(m[i],iminm[i - 1]);
	}

	std::sort(ap,ap + N,[](long long a,long long b){return a > b;});



	return 0;
}