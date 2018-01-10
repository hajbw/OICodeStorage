#include <iostream>

using std::cin;

/*
	P1909 买铅笔
	不完全解法
*/

struct good_set
{
	int amount_of_pencil,price;
};


int main()
{
	int pencils_needed,sets_needed = 0,result = 0;

	good_set pencilset[3];

	cin>>pencils_needed;
	for (int i = 0; i < 3; ++i)
		cin>>pencilset[i].amount_of_pencil>>pencilset[i].price;

	for (int i = 0; i < 3; ++i)
	{
		if(pencils_needed % pencilset[i].amount_of_pencil != 0)
			++sets_needed;
		sets_needed += pencils_needed / pencilset[i].amount_of_pencil;
		result = ((result > pencilset[i].price * sets_needed) || i == 1 ) ? pencilset[i].price * sets_needed : result;
		sets_needed = 0;
	}

	std::cout<<result;

	return 0;
}