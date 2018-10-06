/*
	小奇挖矿2(mining)
*/
#include <iostream>
#include <vector>

#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;
using std::vector;

const int MAXN = 10005,MAXM = 1000000005;

struct hpair
{
	int x,y;

	friend std::istream& operator>>(std::istream &in,hpair &a)
	{
		return in>>a.x>>a.y;
	}

	bool operator<(const hpair &a)
	{
		return y < a.y;
	}
}star[MAXN];
int M,N,dp[MAXN],unable[30];// = {1,2,3,5,6,9,10,13,17};
vector<hpair*> mod4[4],mod7[7];

int main()
{

	int
		ans = 0,dist = 0,//maxval,dsitant_max(dp[])
		a = 0,b;

	unable[1] = unable[2] = unable[3] = unable[5] = unable[6] = unable[9] = unable[10] = unable[13] = unable[17] = 1;

	cin>>N>>M;

	for(int i = 1;i <= N;++i)
	{
		cin>>star[i];
		
		while(a < i && star[i].y - star[a].y > 17)
		{
			++a;
			dist = max(dist,f[a]);
		}

		f[i] = dist;

		for(b = i;star[i].x - star[b].x && b;--b)
		{
			if(!unable[star[i].x - star[b].x])
				f[i] = max(f[i],)
		}

		f[i] += star[i].x;
		ans = max(ans,f[i]);
	}

	cout<<ans;

	return 0;
}