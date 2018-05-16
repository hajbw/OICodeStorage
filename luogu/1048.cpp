#include <iostream>
#include <algorithm>

/*
	P1048 采药
	AC
*/

using std::cin;
using std::cout;
using std::sort;
using std::max;

const int MAXM = 100,MAXT = 1001;

struct Med
{
	int value,cost;
}meds[MAXM];

int f[MAXT];//max_value(cost)

int main()
{
	int T,M;//time meds

	cin>>T>>M;
	for (int i = 0; i < M; ++i)
		cin>>meds[i].cost>>meds[i].value;

	sort(meds,meds + M,[](Med a,Med b) -> bool{return a.cost < b.cost;});

	for (int i = 0; i < M; ++i)//every med
		for (int j = T; j >= meds[i].cost; --j)//time cost -> T
			f[j] = max(f[j],f[j - meds[i].cost] + meds[i].value);

	cout<<f[T];

	return 0;
}
