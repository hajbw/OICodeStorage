/*
	P1047 校门外的树
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXL = 10001;

char road[MAXL];

int main()
{
	int L,M,start,end,ans = 0;

	cin>>L>>M;
	for(int i = 0;i < M;++i)
	{
		cin>>start>>end;
		for(int j = start;j <= end;++j)
			road[j] = 1;
	}

	for(int i = 0;i <= L;++i)
		if(!road[i])
			++ans;

	cout<<ans;

	return 0;
}