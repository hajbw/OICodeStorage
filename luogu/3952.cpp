#include <iostream>
#include <stack>

/*
	* P3952 时间复杂度
*/

using std::cin;
using std::cout;
using std::endl;
using std::stack;

struct loop
{
	char var_name;
	int complexity;

	loop(char var_name,int complexity)
	{
		this.var_name = var_name;
		this.complexity = complexity;
	}
};

int main()
{
	int count,lines_per_program,complexity;
	char ch,*line;
	stack<loop> loops;

	cin>>count;

	for (int i = 0; i < count; ++i)
	{
		cin>>lines_per_program;

		//get estimated complexity
		for (int i = 0; i < 4; ++i)
			cin.get(ch);
		if(ch == '1')
			complexity = 0;
		else
		{
			cin.get();
			cin.get(ch);
			complexity = int(ch - '1' + 1);
		}

		for(int j = 0;j < lines_per_program)
		{
			cin.getline(line,10);

			if(line[0] == 'E')
			{
				if(loops.empty())
				{
					cout<<"ERR"<<endl;
					break;
				}

				loops.pop();
			}

		}
	}

	return 0;
}
