/*
	P3958 奶酪
	AC
*/
#include <iostream>
#include <cstring>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;
using std::memset;

const int MAXN = 1010;

struct poi
{
	long long x,y,z;

	friend std::istream& operator>>(std::istream &in,poi &p)
	{
		return in>>p.x>>p.y>>p.z;
	}
}
poii[MAXN];

int
	fa[MAXN],
	T,N,flag,
	a,b;//temps
long long up[MAXN],down[MAXN],H,R,RR;

inline long long pow2(const long long &a)
{
	return a * a;
}

bool touched(const poi &a,const poi &b)
{
	return pow2(a.x - b.x) + pow2(a.y - b.y) + pow2(a.z - b.z) <= RR;
}

inline int find(const int &x)
{
	while(fa[x] != fa[fa[x]])
		fa[x] = fa[fa[x]];

	return fa[x];
}

int main()
{
	cin>>T;

	while(T--)
	{
		flag = false;
		memset(up	,0,sizeof(long long) * N);
		memset(down	,0,sizeof(long long) * N);
		memset(fa	,0,sizeof(int) * N);
		memset(poii	,0,sizeof(poi) * N);

		cin>>N>>H>>R;

		RR = 4 * R * R;

		for(int i = 1;i <= N;++i)
		{
			fa[i] = i;
			cin>>poii[i];
			up[i]	= poii[i].z + R;
			down[i]	= poii[i].z - R;

		}

		for(int i = 1;i <= N;++i)
		{
			for(int j = 1;j < i;++j)
			{
				if(touched(poii[i],poii[j]))
				{
					a = fa[b = find(i)] = find(j);
					up[a]	= max(up[a],up[b]);
					down[a]	= min(down[a],down[b]);
				}
			}
		}
		
		for(int i = 1;i <= N;++i)
		{
			a = find(i);
			if(up[a] >= H && down[a] <= 0)
			{
				flag = true;
				break;
			}
		}
		cout<<(flag ? "Yes\n" : "No\n");
	}

	return 0;
}