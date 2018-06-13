#include <iostream>
#include <string>
#include <stack>
#include <set>

/*
	* P3952 时间复杂度
*/

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::set;


int main()
{
	int count,lines_per_program,est_complexity,complexity;
	char ch,line[20];
	stack<int> loops;
	set<string> 

	cin>>count;

	for (int i = 0; i < count; ++i)
	{
		cin>>lines_per_program;

		//get estimated complexity
		for (int i = 0; i < 4; ++i)
			cin.get(ch);
		if(ch == '1')
			est_complexity = 0;
		else
		{
			cin.get();
			cin.get();
			cin>>est_complexity;
			cin.getline(line,10);
		}

		//test program line by line
		for(int j = 0;j < lines_per_program)
		{
			cin.getline(line,20);

			if(line[0] == 'E')
			{
				if(loops.empty())
				{
					cout<<"ERR"<<endl;
					while(!loops.empty())
						loops.pop();
					break;
				}

				loops.pop();
			}
			else
			{

			}

		}
	}

	return 0;
}
