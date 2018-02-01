#include <bits/stdc++.h>
#include <windows.h>

/*
leave for comer

author:hajbw
email:hajbw10@126.com
version:0.4.4.5
last changed date:Jan 25,2018
release date:

*/

using namespace std;

void welcome();
void haveFun(int);

const int CODE_MOHA = 1,
      CODE_ENTER_HAJBW = 2,
      CODE_STEAM = 3;

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL,"");
	//another solution
	//locale::global(locale("en_US.UTF-8"));

	//if(argc == 0)//default showing
	{
		welcome();//what should I do next?
		wcout<<u8"让我们找点乐子吧😏\n";
		int code_haveFun;
		cin>>code_haveFun;
		haveFun(code_haveFun);
	}
	/*else//argumented processing(testing)
	{
		for (int i = 0; i < argc; ++i)
		{
			wcout<<argv[i];
		}
		return 0;//exit to get rid of running the codes below


	}*/

	wifstream readme_signature("README_SIGNATURE");
	while(!readme_signature.fail())
		wcout.put(readme_signature.get());

	return 0;
}

void welcome()
{

	wifstream readme_part1("README");
	wchar_t ch;

	//real stuff
	//read char by char
	//notice:
	//$ in readme means to pause
	//# to cls
	//' for comment(ignore the rest of this line)
	//- to stop for .5 second

	//this might be the problem
	//which outputs garbled chars
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
			this_thread::sleep_for(chrono::milliseconds(500));
			break;
		case'\'':
			while(ch != '\n')
				readme_part1.get(ch);
			break;
		default:
			wcout.put(ch);
		}
		this_thread::sleep_for(chrono::milliseconds(20));
		readme_part1.get(ch);
	}

}

void haveFun(int code)
{
	switch(code)
	{
		case CODE_MOHA:
			break;
		case CODE_ENTER_HAJBW:
			break;
		case CODE_STEAM:
			break;
	}
}
