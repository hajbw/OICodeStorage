#include <iostream>
#include <cstring>

/*
	P1047 校门外的树
*/

using std::cin;
using std::cout;

const int MAXL = 10000;

int road[MAXL];

int main()
{
	int L,M,start,end,result = 0;

	cin>>L>>M;

	std::memset(road,19260817,L * sizeof(int));

	for(int i = 0; i < M; ++i)
	{
		cin>>start>>end;
		for (int j = start; j <= end; ++j)
			road[j] = 0;
	}
	for(int i = 0; i <= L; ++i)
		if(road[i])
			++result;
	
	cout<<result;

	return 0;
}
