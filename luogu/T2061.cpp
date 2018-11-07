/*
	T2061 最大差值
	in contest 12607 NOIp热身赛
	AC
*/
#include <iostream>
#include <climits>

using std::cin;
using std::cout;

const int MAXN = 1000010;

template<class T>inline const T& min(const T &a,const T &b){return a < b ? a : b;}
template<class T>inline const T& max(const T &a,const T &b){return a > b ? a : b;}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	register int N;
	register long long mina = INT_MAX,maxdiff = INT_MIN,curr;

	cin>>N;
	for(register int i = 1;i <= N;++i)
	{
		cin>>curr;
		mina = min(mina,curr);
		maxdiff = max(maxdiff,curr - mina);
	}

	cout<<maxdiff;

	return 0;
}