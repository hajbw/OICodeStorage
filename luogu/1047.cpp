#include <iostream>

/*
	P1047 校门外的树
	AC
*/

using std::cin;
using std::cout;

const int MAXL = 10001;

int road[MAXL];

int main()
{
	int L,M,start,end,result = 0;

	cin>>L>>M;

	for(int i = 0; i < M; ++i)
	{
		cin>>start>>end;
		for (int j = start; j <= end; ++j)
			road[j] = 1;
	}
	for(int i = 0; i <= L; ++i)
		if(!road[i])
			++result;
	
	cout<<result;

	return 0;
}
