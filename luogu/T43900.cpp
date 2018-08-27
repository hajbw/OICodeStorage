#include <iostream>
#include <queue>

#define lch(n)	(n<<1)
#define rch(n)	(n<<1|1)
#define fa(n)	(n>>1)

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define DEBUG 1

/**
	T43900 淘汰赛制(elimination.pas/c/cpp)
*/

using std::cin;
using std::cout;
using std::queue;

const int MAXN = 10;

struct hpair
{
	long long possibility;
	int index;

	hpair():possibility(1ll),index(){}
};

int p[1<<MAXN|1][1<<MAXN|1];
hpair tree[1<<(MAXN+1)|3];

template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9')in.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
}

int main()
{
	//std::ios::sync_with_stdio(false);

	int N,cnt;

	read(N);
	cnt = 1 << N;

	for(int i = 1;i <= cnt;++i)
		for(int j = 1;j <= cnt;++j)
			read(p[i][j]);

	//initialize
	for(int i = cnt;i < (cnt<<1|1);++i)
		tree[i].index = i - cnt;

	//then opreate on a fucking perfect bin tree
	for(int i = cnt>>1;i;i >>= 1)
	{
		for(int j = i;j < i << 1;++j)
		{
			tree[lch(j)].possibility *= p[tree[lch(j)].index][tree[rch(j)].index];
			tree[rch(j)].possibility *= p[tree[rch(j)].index][tree[lch(j)].index];
			if(tree[lch(j)].possibility >= tree[rch(j)].possibility)
				tree[j] = tree[lch(j)];
			else
				tree[j] = tree[rch(j)];
		}
	}

#if DEBUG

	for(int i = 0;i < cnt<<1;++i)
		cout<<tree[i].index<<" "<<tree[i].possibility<<"\n";
	cout<<"\n";

	system("pause");
#else

	cout<<tree[1].index;

#endif

	return 0;
}