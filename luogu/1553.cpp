#include <iostream>
#include <string>

/*
	P1553 数字反转（升级版）
*/

using std::cin;
using std::cout;
using std::string;

void trim0(string& str)
{
	while(str.front() == '0' && str != "0")
		str.erase(str.begin());
}

int main()
{
	string str;

	cin>>str;

	if(str.back() == '%')
	{
		str.erase(str.end());
		trim0(str);
		cout<<string(str.rbegin(),str.rend())<<'%';
		return 0;
	}

	for(string::iterator it = str.begin();it != str.end();++it)
	{
		if(*it == '/' || *it == '.')
		{
			string s1(str.begin(),it),s2(it + 1,str.end());
			trim0(s1);
			trim0(s2);
			cout<<string(s1.rbegin(),s1.rend())<<*it<<string(s2.rbegin(),s2.rend());
			return 0;
		}
	}
}