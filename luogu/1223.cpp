/*
	P1223 排队接水
	AC
*/

#include <iostream>
#include <cstdio>
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
	int t;
	double total = 0.0;

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
		total += persons[i].time * (N - i);
	}

	std::printf("\n%.2lf",total / N);

	return 0;
}