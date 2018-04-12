#include <iostream>

/*
	P1424 小鱼的航程(改进版)
	已AC
*/

using namespace std;

int main()
{
	const int distance_per_day = 250,distance_per_week = 1250;
	int x;
	long long n,distance = 0LL;

	cin>>x>>n;

	for (int i = 0; i < n; ++i)
	{
		if(x != 6 && x != 7)
			distance += 250;
		x = ( x == 7 ? 1 : x + 1 );
	}

	cout<<distance;

	return 0;
}