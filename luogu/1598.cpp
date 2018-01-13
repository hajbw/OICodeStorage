#include <iostream>

/*
	P1598 垂直柱状图
*/

using namespace std;

int main()
{
	int[26] alphabet{0};
	char[76] line;
	int index = 0;
	char ch;

	for(int i = 0; i < 4; ++i)
	{
		cin.readline(line,76);

		while(line[index] != '\0')
		{
			ch = line[index];
			if(ch >= 'A' && ch <= 'Z')
			{
				alphabet[ch - 'A']++;
			}
			index++;
		}
	}


	return 0;
}
