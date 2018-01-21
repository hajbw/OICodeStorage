#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <windows.h>

/*
leave for comer

author:hajbw
email:hajbw10@126.com
version:0.4.4.1
last changed date:Jan 21,2018
release date:

*/

using namespace std;

void welcome();

int main(int argc, char const *argv[])
{
	if(argc == 0)
		welcome();
	else
	{
	
	}

	ifstream readme_signature("README_SIGNATURE");
	while(!readme_signature.eof())
		cout.put(readme_signature.get());

	return 0;
}

void welcome()
{

	ifstream readme_part1("README");
	char ch;

	//testing code
	cout<<endl;
	std::this_thread::sleep_for (std::chrono::seconds(1));

	//real stuff
	//read char by char
	//notice: 
	//$ in readme means to pause
	//# to cls
	//' for comment(ignore the rest of this line)
	//- to stop for .5 second

	while(ch = readme_part1.get())
	{
		switch(ch)
		{
			case'$':
			system("pause");
			break;
		case'#':
			system("cls");
			break;
		case'-':
			std::this_thread::sleep_for (std::chrono::miliseconds(500));
			break;
		case'\'':
			while(ch != '\n')
				ch.get();
			break;
		default:
			cout.put(ch);
		}
		std::this_thread::sleep_for (std::chrono::miliseconds(50));

	}

}

