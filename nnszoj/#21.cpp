#include <iostream>

/*
	#21. 哈夫曼编码
*/

using std::cin;
using std::cout;

struct hf_node
{
	int weight;
};

int ascii_table[256];

int main()
{
	char ch;
	int n = 0;//types of chars

	while(cin.get(ch))
		++ascii_table[(int)ch];

	for (int i = 0; i < 256; ++i)
		if(ascii_table[i])
		{
			++n;
		}

	return 0;
}