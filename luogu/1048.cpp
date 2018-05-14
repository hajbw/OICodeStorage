#include <iostream>
#include <algorithm>
#include <cstring>

/*
	P1048 采药
*/

using std::cin;
using std::cout;
using std::sort;

const int MAXM = 100,MAXT = 1000;

struct Med
{
	int value,cost;
}meds[MAXM];

int f[MAXT];

int main()
{
	int T,M;

	cin>>T>>M;
	for (int i = 0; i < M; ++i)
		cin>>meds[i].cost>>meds[i].value;

	sort(meds,meds + M,[](Med a,Med b) -> bool{return a.cost<b.cost;});

	for (int i = 0; i < M; ++i)
	{
		for (int j = meds[i].cost; j < T; ++j)
		{
			f[j] = 
		}
	}

	return 0;
}
