#include <iostream>
#include <cstring>

#ifndef max
#define max(a,b) (a > b ? a : b)
#endif

#ifndef min
#define min(a,b) (a < b ? a : b)
#endif

#ifndef maxx
#define maxx(a,b) if(a < b)a = b
#endif

#ifndef minn
#define minn(a,b) if(a > b)a = b
#endif

/**
	P3958 奶酪
*/

using std::cin;
using std::cout;
using std::endl;
using std::memset;

const int MAXN = 1005,DEBUG = 1,READ_MAX_LINE_LENGTH = 50;

struct hole
{
	int x,y,z;
}
holes[MAXN];

struct uset
{
	int high,low;
}
usets[MAXN];

int fa[MAXN];

char buf[READ_MAX_LINE_LENGTH];
template<class T> void read(T &x,T &y,T &z)
{
	x = y = z = 0;

	char *ptr = buf;
	cin.getline(buf,READ_MAX_LINE_LENGTH);
	int flag = 0;
	while(*ptr < '0' || *ptr > '9')
	{
		flag ^= (*ptr == '-');
		++ptr;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		x = (x<<1) + (x<<3) + (*ptr-'0');//2x+8x+int(*ptr)
		++ptr;
	}
	if(flag)
		x = ~x + 1;
	flag = 0;
	while(*ptr < '0' || *ptr > '9')
	{
		flag ^= (*ptr == '-');
		++ptr;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		y = (y<<1) + (y<<3) + (*ptr-'0');//2y+8y+int(*ptr)
		++ptr;
	}
	if(flag)
		y = ~y + 1;
	flag = 0;
	while(*ptr < '0' || *ptr > '9')
	{
		flag ^= (*ptr == '-');
		++ptr;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		z = (z<<1) + (z<<3) + (*ptr-'0');//2z+8z+int(*ptr)
		++ptr;
	}
	if(flag)
		z = ~z + 1;
}

int find(int v)
{
	if(v != fa[v])
		fa[v] = find(fa[v]);
	return fa[v];
}

long long R;
inline int touch(hole &a,hole &b)
{
	return ((long long)a.x-b.x) * (a.x-b.x) + (a.y-b.y) + (a.y-b.y) + (a.z-b.z) * (a.z-b.z) <= R;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int
		T,n,h,r,
		hole_index,
		x,y,z,
		i,j,k,
		ans;
		
	char str[READ_MAX_LINE_LENGTH];
		
	cin>>T;
	cin.getline(str,READ_MAX_LINE_LENGTH);//cin had EATEN my test data!
	for(i = 0;i < T;++i)
	{
		//initialize,initialize,initialize...
		memset(holes,0,sizeof(holes));
		memset(usets,0,sizeof(usets));
		memset(fa,0,sizeof(fa));

		read(n,h,r);

		//more initializayions && optimizations
		for(j = 0;j < n;++j)
			fa[j] = j;
		hole_index = ans = 0;
		R = long long(r)*r<<2;

		for(j = 0;j < n;++j)
		{
			read(x,y,z);
			if(z < -r || z > h + r)
				continue;
			holes[hole_index].x = x;
			holes[hole_index].y = y;
			holes[hole_index].z = z;
			usets[hole_index].high = z + r;
			usets[hole_index].low = z - r;

			//union touched holes ... O(n^2),sad
			for(k = 0;k < hole_index;++k)
				if(touch(holes[hole_index],holes[k]) &&
					find(hole_index) != find(k))
				{
					fa[hole_index] = k;
					maxx(usets[k].high,usets[hole_index].high);
					minn(usets[k].low,usets[hole_index].low);
				}

			++hole_index;
		}

		for(int j = 0;j < n;++j)
			if(usets[j].high > h && usets[j].low < 0)
			{
				ans = 1;
				break;
			}


		cout<<(ans ? "Yes" : "No")<<endl;
	}

	return 0;
}
