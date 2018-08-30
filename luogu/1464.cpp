#include <iostream>

/**

*/

using std::cin;
using std::cout;

long long w[22][22][22];

template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

long long dfs(const long &a,const long &b,const long &c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return 1ll;
	if(a > 20 || b > 20 || c > 20)
		return w[20][20][20];

	if(w[a][b][c])
		return w[a][b][c];

	if(a < b && b < c)
		w[a][b][c] = dfs(a,b,c - 1ll) + dfs(a,b - 1ll,c - 1ll) - dfs(a,b - 1ll,c);

	return w[a][b][c] = dfs(a - 1ll,b,c) + dfs(a - 1ll,b - 1ll,c) + dfs(a - 1ll,b,c - 1ll) - dfs(a - 1ll,b - 1ll,c - 1ll);
}

int main()
{
	long long a,b,c;

	

	while( ~(1 ^ 1) )
	{
		read(a);read(b);read(c);

		if(a == -1 && b == -1 && c == -1)
			break;

		//w(a, b, c) = ans
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dfs(a,b,c)<<"\n";
	}

	return 0;
}