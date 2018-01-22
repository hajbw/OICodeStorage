#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <windows.h>

/*
leave for comer

author:hajbw
email:hajbw10@126.com
version:0.4.4.3
last changed date:Jan 21,2018
release date:

*/

using namespace std;

void welcome();

int main(int argc, char const *argv[])
{
	if(argc == 0)//default showing
	{
		welcome();//what should I do next?
		int choice;
		cout<<"输入你接下来要做的事\n\n"
		cin>>choice;
		switch(choice)
		{
			case 1:

				break;
			default:
		}

	}
	else//argumented processing(testing)
	{
		for (int i = 0; i < argc; ++i)
		{
			cout<<argv[i];
		}
		return 0;//exit to get rid of running the codes below

		
	}

	ifstream readme_signature("README_SIGNATURE");
	while(!readme_signature.fail())
		cout.put(readme_signature.get());

	return 0;
}

void welcome()
{

	ifstream readme_part1("README");
	char ch;

	//testing code
	cout<<endl;
	this_thread::sleep_for (chrono::seconds(1));

	//real stuff
	//read char by char
	//notice:
	//$ in readme means to pause
	//# to cls
	//' for comment(ignore the rest of this line)
	//- to stop for .5 second

	readme_part1.get(ch);
	while(!readme_part1.fail())
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
			this_thread::sleep_for (chrono::milliseconds(500));
			break;
		case'\'':
			while(ch != '\n')
				readme_part1.get(ch);
			break;
		default:
			cout.put(ch);
		}
		this_thread::sleep_for (chrono::milliseconds(50));
		readme_part1.get(ch);
	}

}

