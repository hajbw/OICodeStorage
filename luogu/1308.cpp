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
		*it = char(std::tolower(*it));
}

int main()
{
	std::ios::sync_with_stdio(false);

	string word,article;

	std::getline(cin,word);
	std::getline(cin,article);

	lower_case(word);
	lower_case(article);

	word = ' ' + word + ' ';
	article = ' ' + article + ' ';

	if(article.find(word) != string::npos)
		cout<<-1;
	else
	{
		int first_index,index,times = 0;
		first_index = index = article.find(word);
		while(index != string::npos)
		{
			++times;
			index = article.find(word,index + 1);
		}
		cout<<first_index<<" "<<times;
	}

	return 0;
}