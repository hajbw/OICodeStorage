#include <iostream>

using namespace std;

/**
	*P1307 数字反转
	*已AC
*/

int main()
{
	char num[12] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char result[12] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	short offset = 0,index = 0;
	bool flag_jump = true;

	cin.getline(num,11);

	if(num[0] == '-')
	{
		result[0] = '-';
		offset++;
	}

	for (int i = 11; i > offset - 1; --i)
	{		
		if(num[i] == '\0')
			continue;
		if(num[i] != 48)
			flag_jump = false;
		if(flag_jump)
			continue;
		result[index + offset] = num[i];
		index++;
		
	}
	cout<<result;

	return 0;
}
