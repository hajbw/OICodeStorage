#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
	P1089 津津的储蓄计划
	已AC
*/

int main()
{
	int MoneyOfMonByHundred = 0,moneyThisMonth,leftThisMonth = 0;

	for (int i = 0; i < 12; ++i)
	{
		cin>>moneyThisMonth;
		leftThisMonth = leftThisMonth + 300 - moneyThisMonth;
		if(leftThisMonth<0)
		{
			cout<< -i - 1;
			return 0;
		}
		if (leftThisMonth > 100)
		{
			MoneyOfMonByHundred += leftThisMonth / 100;
			leftThisMonth = leftThisMonth % 100;
		}
	}
	cout<<leftThisMonth + MoneyOfMonByHundred * 120;
	return 0;
}
