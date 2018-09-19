/*
	P1378 油滴扩展
*/

#include <iostream>
#include <cmath>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;
using std::sqrt;
using std::pow;

const int MAXN = 7;
const double Pi = 3.1415926535897;

template<class T1,class T2>struct hpair
{
	T1 x;
	T2 y;

	friend void operator>>(std::istream &in,hpair &a)
	{
		cin>>a.x>>a.y;
	}
};

hpair<int,int> circles[MAXN];
int xa,ya,xb,yb,N;
double r[MAXN],ans;

double dist(hpair<int,int> &a,hpair<int,int> &b)
{
	return sqrt((double)pow(a.x - b.x,2) + pow(a.y - b.y,2));
}

double maxr(const int &o)
{
	for(int i = 0;i < N;++i)
		if(i != o && r[i])
			if(r[i] > dist(circles[i],circles[o]))
				return 0.0;

	double dis,ans = min(min(circles[o].x - xa,xb - circles[o].x),min(circles[o].y - ya,yb - circles[o].y));
	for(int i = 0;i < N;++i)
	{
		if(i != o && r[i])
		{
			dis = dist(circles[i],circles[o]) - r[i];
			ans = min(ans,dis);
		}
	}
	return ans;
}

void dfs(int o,double square)
{
	if(o == N)
	{
		if(square < ans)
			ans = square;
	}
	else
		for(int i = 0;i < N;++i)
			if(!r[i])
				r[i] = maxr(i),
				dfs(o + 1,square - Pi * r[i] * r[i]),
				r[i] = 0.0;
}

int main()
{
	cin>>N;
	cin>>xa>>ya>>xb>>yb;

	{
		int temp;
		if(xb < xa)
		{
			temp = xb;
			xb = xa;
			xa = temp;
		}
		if(yb < ya)
		{
			temp = yb;
			yb = ya;
			ya = temp;
		}
	}

	for(int i = 0;i < N;++i)
		cin>>circles[i];

	dfs(0,ans = (xb - xa) * (yb - ya));

	cout<<int(ans + 0.5);

	return 0;
}