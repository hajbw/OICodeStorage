#include <iostream>
#include <vector>
#include <string>
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
using std::map;

class Alkane
{
public:
	const char mapping[2] = {'H','C'};

	Alkane();
	Alkane(string to_parse);


private:
	vector<vector<int>> graph,rev_graph;



}

void intro();
void help();

int main()
{
	map<string, Alkane> map;
	string command;
	char ch;

	intro();

	while(true)
	{
		cout>>"\n ->";
		while(ch != ' '||ch != '\n')
		{
			cin.get(ch);
			command += ch;
		}
		if(command == "exit")
			break;
		else if(command == "")
	}

	return 0;
}

void intro()
{
	cout<<"hajbw Alkane shower.";
}

void help()
{
	cout<<
}