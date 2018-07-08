#include <iostream>
#include <string>

/*
	P1914 小书童——密码
*/

using std::cin;
using std::cout;
using std::string;

int main()
{
	int n;
	string str;

	cin>>n>>str;

	for(string::iterator it = str.begin();it != str.end();++it)
		*it = char( (*it + n - 'a') % 26 + 'a' );

	cout<<str;
}