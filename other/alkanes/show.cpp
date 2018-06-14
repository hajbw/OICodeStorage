#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

/*
	hajbw alkane processor
	intend to:
		store a few alkane
		I/O with different type


	author:hajbw
	version:v0.0.1(1)-alpha
*/

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;
using std::map;

typedef int PROC_CTRL;

const PROC_CTRL
	PROC_EXIT = 0;

class Alkane
{
public:

	static const char *periodic_table[108] = {"H","He","Li","Be","B","C","N","O"};

	/*
	class Element
	{
		int order;
	}
	*/

	Alkane();
	Alkane(string name,string expression)
	{
		stack<char> st;
		for(string::iterator it = expression.begin();it != expression.end();++it)
		{

		}
	}


private:



}

void intro();
void help(string query);
PROC_CTRL process(vector<string> &commands);

int main(int argc, char const *argv[])
{
	map<string, Alkane> alkanes;

	intro();

	while(true)
	{
		string temp;
		vector<string> commands;

		cout>>"\n->";
		while(cin>>temp)
			commands.push_back(temp);

	}

	return 0;
}

void intro()
{
	cout<<"hajbw Alkane shower,version 0.0.1(1).";
}

void help(string query)
{
	if(!query)
	{
		intro();
		cout<<"\n\nThese are all internally supported commands.\n\n"<<
			"Type \"help [command]\" to get detailed help about [command].\n"<<
			"exit\n"<<
			"alkane [name] = [expression]\n"<<
			"output [name]";
	}

}

PROC_CTRL process(vector<string> &commands)
{
	if(commands[0] == "exit")
		return PROC_EXIT;
	else if(commands[0] == "alkane")
	{
		if(alkanes.count(name))
			cout<<"\""<<name<<"\" already exist."
		else
		{
			alkanes.insert();
		}

	}
	else if(commands[0] == "output")
	{
		map::iterator it;
		it = alkanes.find(name);
		if(it == alkanes.end())
			cout<<"\""<<name<<"\" does not exists!";
		else
		{
			cout<<it->second
		}
	}
	else
		cout<<"commands not supported!";
}