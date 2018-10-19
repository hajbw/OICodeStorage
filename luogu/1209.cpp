/*
	P1209 [USACO1.3]修理牛棚 Barn Repair
	AC
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXM = 55,MAXS = 205;

int M,S,C,stall_number[MAXS],space[MAXS],ans;
std::greater<int> cmp;

int main()
{
	cin>>M>>S>>C;
	for(int i = 1;i <= C;++i)
		cin>>stall_number[i];

	std::sort(stall_number + 1,stall_number + 1 + C);

	for(int i = 1;i <= C;++i)
		space[i] = stall_number[i] - stall_number[i - 1] - 1;

	std::sort(space + 2,space + 1 + C,cmp);

	ans = stall_number[C] - space[1];

	for(int i = 2;i <= M;++i)
	{
		if(!space[i])
			break;
		ans -= space[i];
	}

	cout<<ans;

	return 0;
}