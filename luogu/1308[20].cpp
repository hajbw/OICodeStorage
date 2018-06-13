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
		*it = char(std::tolower(*it));
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	string word,article;
	int first_index = -1,index = -1,times = 0;

	cin>>word;

	lower_case(word);

	while(cin>>article)
	{
		lower_case(article);
		++index;
		if(word == article)
		{
			if(first_index < 0)
				first_index = index;
			++times;
		}
	}

	if(first_index < 0)
		cout<< -1;
	else
		cout<<times<<" "<<first_index;

	return 0;
}