#include <iostream>

#define DEBUG 1

#if DEBUG
#include <windows.h>
#endif
/**
	P1049 装箱问题
*/

using std::cin;
using std::cout;

const int MAXN = 31,MAXV = 20020;

int
	v[MAXN],
	reachable[MAXV] = {1};

int read()
{
	char ch = '\0';int x = 0;
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch -'0';cin.get(ch);}
	return x;
}

int main()
{
	int V = read(),N = read(),i,j;
	for(i = 0;i < N;++i)
		v[i] = read();

	for(i = 0;i < N;++i)
		for(j = V - v[i];j > 0;--j)
			if(reachable[j])
				reachable[j + v[i]] = 1;

	for(i = V;i >= 0 && !reachable[i];--i) ;
	cout<<V - i;

#if DEBUG
	system("pause");
#endif

	return 0;
}