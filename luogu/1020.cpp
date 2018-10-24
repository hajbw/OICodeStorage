/*
	P1020 导弹拦截
	AC
*/
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXN = 200020,INF = 0x7f7f7f7f;

int arr[MAXN],acs[MAXN],des[MAXN],cnt;
std::greater<int> rev_cmp;
bool wtf_cmp(int a,int b){return b == 0;}

template<class T> bool read(T &x)
{
	char ch = '\0';bool flag = 0;x = 0;
	cin.get(ch);
	while((ch < '0' || ch > '9') && cin.good()){flag ^= (ch == '-');cin.get(ch);}
	if(!cin.good())return false;
	while(ch >= '0' && ch <= '9' && cin.good()){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
	if(flag)x = -x;
	return true;
}

int main()
{
	while(read(arr[cnt++])) ;

	--cnt;

	std::memset(acs,0x7f,sizeof(int) * cnt);

	for(int i = 0;i < cnt;++i)
		*std::upper_bound(des,des + i + 1,arr[i],rev_cmp) = arr[i];

	cout<<std::lower_bound(des,des + cnt + 1,0,rev_cmp) - des<<'\n';

	for(int i = 0;i < cnt;++i)
		*std::lower_bound(acs,acs + i + 1,arr[i]) = arr[i];

	cout<<std::lower_bound(acs,acs + cnt + 1,INF) - acs<<'\n';

	return 0;
}