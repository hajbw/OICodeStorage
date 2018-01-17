#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

/*
leave for comer
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

