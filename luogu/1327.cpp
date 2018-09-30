/*
	P1327 数列排序
*/
#include <iostream>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::map;

const int MAXN = 100010;

int arr[MAXN],brr[MAXN];
map<int,int> order;

int readInt()
{
	char ch = '\0';int flag = false,res = 0;
	cin.get(ch);
	while((ch < '0' || ch > '9') && cin.good()){flag ^= (ch == '-');cin.get(ch);}
	while(ch >= '0' && ch <= '9'){res = (res<<1) + (res<<3) + ch - '0';cin.get(ch);}
	if(flag)
		res = -res;
	return res;
}

int main()
{
	int N,a;

	N = readInt();
	for(int i = 0;i < N;++i)
		order[arr[i] = brr[i] = readInt()] = i;

	for(map<int,int>::iterator it = order.begin();it != order.end();++it)
		cout<<it->first<<'\t'<<it->second<<'\n';
}