#include <iostream>

/*
	P1567 统计天数
*/

using std::cin;
using std::cout;

int main()
{
	int N,maxd = 0,curr_maxd = 0,curr,last = 0;

	cin>>N;
	cin>>last;
	for (int i = 1; i < N; ++i)
	{
		cin>>curr;
		if(curr > last)
		{
			++curr_maxd;
		}
		else
		{
			if(curr_maxd > maxd)
				maxd = curr_maxd;
			curr_maxd = 0;
		}
		last = curr;
	}
}