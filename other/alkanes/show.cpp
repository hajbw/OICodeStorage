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

*/

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;
using std::map;

class Alkane
{
public:
	const char mapping[2] = {'H','C'};

	Alkane();
	Alkane(string to_parse)
	{
		stack<char> st;
		for(string::iterator it = to_parse.begin();it != to_parse.end();++it)
		{

		}
	}


private:
	vector<vector<int>> graph,rev_graph;



}

void intro();
void help();

int main()
{
	map<string, Alkane> alkanes;

	intro();

	string command;
	char ch;
	while(true)
	{
		cout>>"\n->";
		cin>>command;
		if(command == "exit")
			break;
		else if(command == "alkane")
		{
			string name,xpr;
			cin>>name>>xpr;
			if(alkanes.count(name))
				cout<<"\""<<name<<"\" already exist."
			else
			{
				alkanes.insert()
			}

		}
		else if(command == "output")
		{
			string name;
			map::iterator it;
			cin>>name;
			it = alkanes.find(name);
			if(it == alkanes.end())
				cout<<"\""<<name<<"\" does not exists!";
			else
			{
				cout<<it->second
			}
		}
		else
			cout<<"command not supported!";
	}

	return 0;
}

void intro()
{
	cout<<"hajbw Alkane shower.";
}

void help()
{
	cout<<"";
}