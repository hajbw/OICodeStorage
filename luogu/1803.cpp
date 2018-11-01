/*
	P1803 凌乱的yyy / 线段覆盖
	AC
*/
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXN = 1000010;

struct hpair
{
	int x,y;

	bool operator<(const hpair &a)const
	{
		return y == a.y ? x > a.x : y < a.y;
	}

	friend std::istream& operator>>(std::istream &in,hpair &a)
	{
		return in>>a.x>>a.y;
	}
}
contests[MAXN];

int dp[MAXN],N,ans,right;

template<class T>inline const T& min(const T &a,const T &b){return a < b ? a : b;}
template<class T>inline const T& max(const T &a,const T &b){return a > b ? a : b;}

int main()
{
	cin>>N;
	for(int i = 1;i <= N;++i)
		cin>>contests[i];

	std::sort(contests + 1,contests + 1 + N);

	++ans;
	right = contests[1].y;
	for(int i = 2;i <= N;++i)
	{
		if(contests[i].x >= right)
		{
			++ans;
			right = contests[i].y;
		}
	}

	cout<<ans;

	return 0;
}