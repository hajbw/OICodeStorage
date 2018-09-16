#include <cstdio>
#include <cstring>
#include <algorithm>

/**
	P1223 排队接水
	82
*/

using std::scanf;
using std::printf;

const int MAXN = 1005;

struct rnl
{
	int order,time;
}
arr[MAXN];

int main()
{
	int
		n,curr_time = 0,//arr[i]'s waiting time
		total_time = 0;//total wating time

	scanf("%d",&n);
	for(int i = 1;i <= n;++i)
	{
		arr[i].order = i;
		scanf("%d",&arr[i].time);
	}

	std::sort(arr + 1,arr + n + 1,[](rnl &a,rnl &b) -> bool{return a.time < b.time;});

	for(int i = 1;i <= n;++i)
	{
		printf("%d ",arr[i].order);
		total_time += arr.time * (n - i);
	}

	printf("\n%.2f",double(total_time) / n);

	return 0;
}