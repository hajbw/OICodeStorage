#include <iostream>

/**
	T43900 淘汰赛制(elimination.pas/c/cpp)
*/

using std::cin;
using std::cout;

const int MAXN = 11;

int N,p[MAXN][MAXN],posibility[1<<MAXN];

template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9')in.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
}

int main()
{
	read(N);

	for(int i = 0;i < (1<<N);++i)
		for(int j = 0;j < (1<<N);++j)
			read(p[i][j]);

	

	return 0;
}