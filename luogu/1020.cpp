/*
	P1020 导弹拦截
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXN = 200020;

int arr[MAXN],acs[MAXN],des[MAXN],cnt;

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
	while(cin>>arr[cnt++]) ;

}