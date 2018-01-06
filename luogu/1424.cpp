#include <iostream>

/*
	P1424 小鱼的航程(改进版)
*/

using namespace std;

int main()
{
	const int distance_per_day = 250,distance_per_week = 1250;
	int x;
	long long n,distance;

	cin>>x>>n;

	distance = distance_per_week * (n / 7);

	if(x < 6 && n % 7 + x > 5)
	{
		distance += (6 - x) + (n % 7 + x - 5); 
	}
	else
		distance += distance_per_day * (n % 7);

	cout<<distance;

	return 0;
}