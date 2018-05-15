#include <iostream>

/*
	P1428 小鱼比可爱
	已AC
*/

using std::cin;
using std::cout;

const int MAXN = 100;

int fish_kawaiility[MAXN],kawaiility_fish[MAXN];

int main()
{
	int n,kawaiility,fishes;
	cin>>n;
	for(int i = 0;i < n;++i)
	{
		cin>>kawaiility;
		fish_kawaiility[i] = kawaiility;
		++kawaiility_fish[kawaiility];

		fishes = 0;
		for (int i = 0; i < kawaiility; ++i)
			fishes += kawaiility_fish[i];
		cout<<fishes<<" ";
	}


	return 0;

}
