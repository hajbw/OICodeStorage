/*
	CF47E Cannon
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;
using std::sin;
using std::cos;

const int MAXN = 1010,MAXM = 10010;

struct wall
{
	double x,y;

	bool operator<(wall &a)const
	{
		return x == a.x ? y > a.y : x < a.x;
	}

	friend std::istream& operator>>(std::istream &in,wall &a)
	{
		return in>>a.x>>a.y;
	}
}
w[MAXM];
double alpha[MAXN],currx;

int N,V,M;

inline int isabove(const double &a,const wall &w)
{
	double
		t = w.x / V / cos(a),
		y = V * sin(a) * t - 4.9 * t * t;

	if(y <= 0.0)
		return -1;
	else if(y > w.y)
		return 1;
	else
		return 0;
}

inline double landx(const double &a)
{
	return 2.0 * V * V * sin(a) * cos(a) / 4.9;
}

int main()
{
	cin>>N>>V;
	for(int i = 1;i <= N;++i)
		cin>>alpha[i];
	cin>>M;
	for(int i = 1;i <= M;++i)
		cin>>w[i];

	std::sort(alpha + 1,alpha + 1 + N);
	std::sort(w + 1, w + 1 + M);

	for(int i = 1;i <= N;++i)
	{

	}
}