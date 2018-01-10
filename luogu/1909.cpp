#include <iostream>

using namespace std;

/*
	P1909 买铅笔
*/


struct good_set
{
	int amount_of_pencil,price;
};

int main()
{
	int i,j,pencils_needed,result = 0,pencils[10002];
	good_set pencilset[3];

	cin>>pencils_needed;
	for (i = 0; i < 3; ++i)
		cin>>pencilset[i].amount_of_pencil>>pencilset[i].price;

	for (i = 0; i < 3; ++i)
	{
		for (j = pencils_needed; j >= pencilset[i].amount_of_pencil ; --j)
		{
			pencils[i] = (
				pencils[i] < pencils[i - pencilset[i].amount_of_pencil] + pencilset[i].price ?
				pencils[i - pencilset[i].amount_of_pencil] + pencilset[i].price :
				pencils[i]
				);
		}
	}

	result = pencils[pencils_needed];

	cout<<result;

	return 0;
}
