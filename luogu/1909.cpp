#include <iostream>

using namespace std;

/*
	P1909 买铅笔
*/


struct set
{
	int amount_of_pencil,price;
};

int main()
{
	int pencils_needed,result = 0,pencils[10000];
	set pencilset[3];

	cin>>pencils_needed;
	for (int i = 0; i < 3; ++i)
	{
		cin>>pencilset[i].amount_of_pencil>>pencilset[i].price;
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = pencils_needed; j >= pencilset[i].amount_of_pencil ; --j)
		{
			
		}
	}

	cout<<result;

	return 0;
}
