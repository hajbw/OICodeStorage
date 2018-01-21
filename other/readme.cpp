#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <windows.h>

/*
leave for comer

author:hajbw
email:hajbw10@126.com
version:0.4.3
last changed date:Jan 21,2018
release date:

*/

using std::cout;
using std::endl;
using std::cin;

int main()
{
	ifstream readme_part1("README");
	ifstream readme_signature("README_SIGNATURE");
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
		std::this_thread::sleep_for (std::chrono::miliseconds(100));

	}

	return 0;
}

