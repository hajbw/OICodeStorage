#include <iostream>
#include <cstdio>

/*
	P1422 小玉家的电费
	已AC
*/

using namespace std;

int main()
{
	int usedEletricity;
	double result;

	cin>>usedEletricity;

	if (usedEletricity<151)
	{
		result = usedEletricity * 0.4463;
	}
	else if (usedEletricity<401)
	{
		result = usedEletricity * 0.4663 - 3.0;
	}
	else
	{
		result = usedEletricity * 0.5663 - 43.0;
	}

	printf("%.1f",result);

	return 0;
}
