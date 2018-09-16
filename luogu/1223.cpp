/*
	P1223 排队接水
*/

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXN = 1005;

struct hpair
{
	int index,time;

	bool operator<(hpair &a)
	{
		return time == a.time ? index < a.index : time < a.time;
	}
}
persons[MAXN];

int N;

int main()
{
	int t,total = 0;

	cin>>N;
	for(int i = 1;i <= N;++i)
	{
		cin>>t;
		persons[i] = (hpair){i,t};
	}

	std::sort(persons + 1,persons + N + 1);

	for(int i = 1;i <= N;++i)
	{
		cout<<persons[i].index<<" ";
		total += persons[i].time * (N - i + 1);
	}

	cout.precision(2);
	cout<<"\n"<<(double(total) / N);
}