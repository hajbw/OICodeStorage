#include <iostream>

using namespace std;

int main()
{
	char num[12] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char result[12] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	short offset = 0,index = 0;
	cin.getline(num,11);
	if(num[0] == '-')
	{
		result[0] = '-';
		offset++;
	}
	for (int i = 11; i > offset - 1; --i)
	{
		if(num[i] != '\0' && num[i] != '0')
		{
			result[index + offset] = num[i];
			index++;
		}
	}
	cout<<result;
	return 0;
}
