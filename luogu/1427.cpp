#include <iostream>
#include <stack>

/*
	P1427 小鱼的数字游戏
	AC
*/

using std::cin;
using std::cout;
using std::stack;

int main()
{
	stack<int> num;
	int input = 0;
	while(true)
	{
		cin>>input;
		if(!input)
			break;
		num.push(input);
	}
	while(!num.empty())
	{
		cout<<num.top()<<" ";
		num.pop();
	}
	return 0;
}