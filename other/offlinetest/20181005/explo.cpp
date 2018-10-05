/*
	小奇挖矿(explo)
*/
#include <iostream>

#define DEBUG 0

using std::cin;
using std::cout;

const int MAXN = 100005;

struct hpair
{
	//note:
	//	typ:	1 -> resource
	//			2 -> repair
	int typ,val;

	hpair():typ(0),val(0){}
	hpair(int t,int v):typ(t),val(v){}

	friend std::istream& operator>>(std::istream &in,hpair &a)
	{
		in>>a.typ>>a.val;
		return in;
	}
}
star[MAXN];
int N,K,C,W;
double dp[MAXN];

template<class T>inline T min(const T &a,const T &b){return a < b ? a : b;}
template<class T>inline T max(const T &a,const T &b){return a > b ? a : b;}

int main()
{
#if !DEBUG
	freopen("explo.in","r",stdin);
	freopen("explo.out","w",stdout);
#endif

	cin>>N>>K>>C>>W;
	for(int i = 1;i <= N;++i)
		cin>>star[i];

	double
		p1 = 1 - (0.01 * K),
		p2 = 1 + (0.01 * C);
	if(star[N].typ == 1)
		dp[N] = star[N].val;

	for(int i = N - 1;i;--i)
	{
		if(star[N].typ == 1)
			dp[i] = max(dp[i + 1],dp[i + 1] * p1 + star[i].val);
		else
			dp[i] = max(dp[i + 1],dp[i + 1] * p2 - star[i].val);
	}

	printf("%.2lf",dp[1] * W);

	return 0;
}