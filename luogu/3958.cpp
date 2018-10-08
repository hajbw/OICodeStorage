/*
	P3958 奶酪
*/
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::memset;

const int MAXN = 1010;

struct poi
{
	long long x,y,z;

	friend std::istream& operator>>(std::istream &in,poi &p)
	{
		return in>>x>>y>>z;
	}
}
poii[MAXN];

int fa[MAXN],up[MAXN],down[MAXN],T,N,H,RR;

inline long long pow2(const long long &a)
{
	return a * a;
}

bool touched(const poi &a,const poi &b)
{
	return pow2(a.x - b.x) + pow2(a.y - b.y) + pow2(a.z - b.z) <= RR;
}

int main()
{
	cin>>T;

	while(T--)
	{
		memset(up,0,sizeof(typeof(up)) * N);

		cin>>N>>H>>RR;
		RR *= RR;
	}
}