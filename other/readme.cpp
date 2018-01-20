#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

/*
leave for comer

author:hajbw
email:hajbw10@126.com
version:0.4
last changed date:Jan 20,2018
release date:

*/

using std::cout;
using std::endl;
using std::cin;

int main()
{
	ifstream input("readme");
	char * line,ch;
	int index;

	//testing code
	cout<<endl;
	std::this_thread::sleep_for (std::chrono::seconds(1));

	//real stuff
	//read per line of readme then show
	//notice: $ in readme means to pause,# to cls
/*
 
	while(input.readline())
	{

	while(ch = line[index]){
		cout.put(ch);
		std::this_thread::sleep_for (std::chrono::miliseconds(100));
		index++;
	}

	std::this_thread::sleep_for (std::chrono::seconds(1));


	}

*/

	return 0;
}

