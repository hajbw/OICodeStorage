/*
	小奇挖矿(explo)
*/
#include <iostream>

#define DEBUG 1

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

template<class T>inline T min(const T &a,const T &b){return a < b ? a : b;}
template<class T>inline T max(const T &a,const T &b){return a > b ? a : b;}

double dfs(int i,int s,double p,double w)
//s : if to choose current
//w : money
//p : abiity
{
	if(i > N)
		return w;

	if(s)
	{
		if(star[i].typ == 1)//res
		{
			w += star[i].val * p;
			p *= (1 - 0.01 * K); 
		}
		else//rep
		{
			w -= star[i].val * p;
			p *= (1 + 0.01 * C);
		}
	}

	return
	max(
		dfs(i + 1,0,p,w),
		dfs(i + 1,1,p,w)
	);

}

int main()
{
#if !DEBUG
	freopen("explo.in","r",stdin);
	freopen("explo.out","w",stdout);
#endif

	cin>>N>>K>>C>>W;
	for(int i = 1;i <= N;++i)
		cin>>star[i];

	printf("%.2lf",dfs(0,0,W,0.0));

	return 0;
}