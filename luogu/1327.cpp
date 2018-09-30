/*
	P1327 数列排序
	happen to be AC
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
	int N,a,ans = 0,i = 0;

	N = readInt();
	for(int i = 0;i < N;++i)
		order[arr[i] = brr[i] = readInt()] = i;

	for(map<int,int>::iterator it = order.begin();i < N;++i,++it)
	{
		if(arr[i] == it->first)
			continue;
		++ans;
		a = it->second;
		order[arr[i]] = a;
		arr[a] = arr[i];
	}

	cout<<ans;

	return 0;
}