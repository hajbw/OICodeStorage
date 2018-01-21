#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

/*
leave for comer

author:hajbw
email:hajbw10@126.com
version:0.4.1
last changed date:Jan 20,2018
release date:

*/

using std::cout;
using std::endl;
using std::cin;

int main()
{
	ifstream readme_part1("README");
	ifstream readme_signature("README_SIGNATURE");
	char * line,ch;
	int index;

	//testing code
	cout<<endl;
	std::this_thread::sleep_for (std::chrono::seconds(1));

	//real stuff
	//read per line of readme then show
	//notice: 
	//$ in readme means to pause
	//# to cls
	//- for comment(ignore the rest of this line)
/*
 
	while(readme_part1.readline())
	{

	while(ch = line[index]){

	if(ch = '$')//change into switch!
	system("pause");
	else if(ch = '#')
	system("cls");
	else if(ch = '-')
	break;
	else{

		cout.put(ch);
		std::this_thread::sleep_for (std::chrono::miliseconds(100));

		index++;
	}
	}


	}

*/

	return 0;
}

