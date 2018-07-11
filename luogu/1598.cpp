#include <iostream>
#include <cstring>

#define max(a,b) (a > b ? a : b)

/*
	P1598 垂直柱状图
*/

using std::cin;
using std::cout;
using std::endl;

int alphabet[26];//counter,a[0] for 'A'

int main()
{
	char line[105];//unable to convert const char[52] to char[105] ... wtf
	int max_count = 0;

	//read and sum up the words
	for(int i = 0; i < 4; ++i)
	{
		cin.getline(line,101);

		for(int i = 0;line[i] != '\0';++i)
			if(line[i] >= 'A' && line[i] <= 'Z')
				alphabet[line[i] - 'A']++;
	}

	//calculate lines 2 output(m_count + 1 in total)
	for (int i = 0; i < 26; ++i)
		max_count = max(max_count,alphabet[i]);

	//output
	std::memset(line,0,sizeof(line));
	for(int i = max_count;i > 0;--i)
	{
		line = "                                                   ";//26+25 spaces
		for(int j = 0;j < 26;++j)
			if(alphabet[j] >= i)
				line[j * 2] = '*';
		cout<<line<<endl;
	}

	cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";

	return 0;
}
