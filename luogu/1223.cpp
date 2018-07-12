#include <iostream>
#include <cstring>
#include <algorithm>

/**
	P1223 排队接水
*/

using std::cin;
using std::cout;

const int MAXN = 1005;

struct rnl
{
	int order,time;
}
arr[MAXN];

int main()
{
	int n,total_time = 0;

	cin>>n;
	for(int i = 1;i <= n;++i)
	{
		arr[i].order = i;
		cin>>arr[i].time;
	}

	std::sort(arr + 1,arr + n + 1,[](rnl a,rnl,b) -> bool{return a.time < b.time;});

	for(int i = 1;i <= n;++i)
		cout<<arr[i].order<<" ";

	//..

	cout<<std::endl<<   <<float(total_time) / n;
}