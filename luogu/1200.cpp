#include <iostream>
#include <string>

/*
	P1200 [USACO1.1]你的飞碟在这儿
	AC
*/

using std::cin;
using std::cout;
using std::string;

string namea,nameb;

int main()
{
	int codea = 1,codeb = 1;

	cin>>namea>>nameb;

	for (string::iterator i = namea.begin(); i != namea.end(); ++i)
		codea *= *i - 64;

	for (string::iterator i = nameb.begin(); i != nameb.end(); ++i)
		codeb *= *i - 64;

	codea %= 47;
	codeb %= 47;

	cout<< (codea == codeb ? "GO" : "STAY");

}
