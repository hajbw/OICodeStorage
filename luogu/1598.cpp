#include <iostream>

/*
	P1598 垂直柱状图
*/

using namespace std;

int main()
{
	int[26] alphabet{0};//counter,0 for 'A'
	char[76] line;
	int index = 0,max_count = 0;
	char ch;

	//read and sum the words
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

	//calculate lines 2 output(m_count + 1 in total)
	for (int i = 0; i < 26; ++i)
		max_count = alphabet[i] > max_count ? alphabet : max_count;

	for (int i max_count; i > 0; --i)
	{
		
	}

	cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"

	return 0;
}
