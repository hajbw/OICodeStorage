#include <iostream>

using namespace std;

/**
	*P1055 ISBN号码
	*已AC
*/

int main()
{

	char isbn[13],identify;
	int sum = 0,mod,mapping[9] = {0,2,3,4,6,7,8,9,10};

	cin.get(isbn,14);

	for (int i = 1; i < 10; ++i)
		sum += ((int) isbn[mapping[i-1]] - '0')*i;

	mod = sum % 11;
	identify = (mod == 10)?'X':mod+'0';

	if(isbn[12]==identify)
		cout<<"Right";
	else
	{
		isbn[12]=identify;
		cout<<isbn;
	}

	return 0;
}
