#include <iostream>

using namespace std;

/*
	P1909 买铅笔
*/

int main()
{
	int amount[3],price[3],i,j,pencils_needed,result = 0,pencils[10002];
	good_set pencilset[3];

	cin>>pencils_needed;
	for (i = 0; i < 3; ++i)
		cin>>price[i]>>pencilset[i].price;

	for (i = 0; i < 3; ++i)
	{
		for (j = pencils_needed; j >= price[i] ; --j)
		{
			pencils[i] = (
				pencils[i] < pencils[i - price[i]] + price[i] ?
				pencils[i - price[i]] + price[i] :
				pencils[i]
				);
		}
	}

	result = pencils[pencils_needed];

	cout<<result;

	return 0;
}
