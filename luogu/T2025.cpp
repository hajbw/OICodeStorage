/*
	T2025 攀爬者
	in contest 12607 NOIp热身赛
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXN = 50005;

struct htriple
{
	double x,y,z;

	friend std::istream& operator>>(std::istream &in,htriple &a)
	{
		return in>>a.x>>a.y>>a.z;
	}

	bool operator<(const htriple &a)const
	{
		return x < a.x;
	}
}
tops[MAXN];

template<class T>T pow2(const T &a){return a * a;}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin>>N;
	for(register int i = 0;i < N;++i)
		cin>>tops[i];

	std::sort(tops,tops + N);

	double ans = 0.0;
	for(register int i = 1;i < N;++i)
		ans += std::sqrt(pow2(tops[i].x - tops[i-1].x) + pow2(tops[i].y - tops[i-1].y) + pow2(tops[i].z - tops[i-1].z));;

	std::printf("%.3lf",ans);

	return 0;
}