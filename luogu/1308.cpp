#include <iostream>
#include <string>

/*
	P1308 统计单词数
*/

using std::cin;
using std::cout;
using std::string;

void lower_case(string &str)
{
	for(string::iterator it = str.begin();it != str.end();++it)
	{
		//loweracse *it (char)
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	string word,article;
	int ans = -1,index = -1;

	cin>>word;

	lower_case(word);

	while(cin>>article)
	{
		lower_case(article);
		++index;
		
	}

	return 0;
}