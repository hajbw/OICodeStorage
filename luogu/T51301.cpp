/*
	T51301 最小N个和
	AC
*/
#include <iostream>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;

const int MAXN = 100010;

struct triple
{
	int x,y,v;

	triple(){}
	triple(int x,int y,int v):x(x),y(y),v(v){}

	bool operator<(const triple &a)const
	{
		return v > a.v;
	}
};

int N,arr[MAXN],brr[MAXN],cnt;
std::priority_queue<triple> quq;
triple a;

int main()
{
	cin>>N;
	for(int i = 0;i < N;++i)
		cin>>arr[i];
	for(int i = 0;i < N;++i)
		cin>>brr[i];

	std::sort(arr,arr + N);
	std::sort(brr,brr + N);

	for(int i = 0;i < N;++i)
		quq.push(triple(i,i,arr[i] + brr[i]));

	for(cnt = 0;cnt < N;++cnt)
	{
		a = quq.top();
		quq.pop();

		cout<<a.v<<' ';

		if(a.x <= a.y)
			quq.push(triple(a.x,a.y + 1,arr[a.x] + brr[a.y + 1]));
		if(a.x >= a.y)
			quq.push(triple(a.x + 1,a.y,arr[a.x + 1] + brr[a.y]));

	}

	return 0;
}