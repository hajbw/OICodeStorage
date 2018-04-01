#include <iostream>

using namespace std;

/*
	P1909 买铅笔
*/

int main()
{
	int amount[3],price[3],order[3],i,ii,j,pencils_needed,result = 0,pencils[10002];

	cin>>pencils_needed;
	for (i = 0; i < 3; ++i)
	{
		cin>>price[i]>>pencilset[i].price;
	}
	
	//todo: complete order[];

	for (ii = 0; ii < 3; ++ii)
	{
		i = order[ii];
		for (j = pencils_needed; j >= price[i] ; --j)
		{
			pencils[i] = (
				pencils[i] > pencils[i - price[i]] + price[i] ?
				pencils[i - price[i]] + price[i] :
				pencils[i]
				);
		}
	}

	result = pencils[pencils_needed];

	cout<<result;

	return 0;
}
