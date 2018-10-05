/*
	小奇挖矿(explo)
*/
#include <iostream>

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
double dp[MAXN][2];//max-val(i,choose-curr)
double w[MAXN][2];
int N,K,C,W;

template<class T>inline T min(const T &a,const T &b){return a < b ? a : b;}
template<class T>inline T max(const T &a,const T &b){return a > b ? a : b;}

int main()
{
	freopen("explo.in","r",stdin);
	freopen("explo.out","w",stdout);

	cin>>N>>K>>C>>W;
	for(int i = 1;i <= N;++i)
		cin>>star[i];

	return 0;
}