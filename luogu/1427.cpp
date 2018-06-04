#include <iostream>
#include <stack>

/*
	P1427 小鱼的数字游戏
*/

using std::cin;
using std::cout;
using std::stack;

int main()
{
	stack<int> num;
	int input;
	while(cin>>input)
		num.push(input);
	while(num.empty())
	{
		cout<<num.front();
		num.pop();
	}
}