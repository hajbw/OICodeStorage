#include <iostream>

/*
	P1425 小鱼的游泳时间
	已AC(但是我就是要写题解！)
*/

using std::cin;
using std::cout;
using std::endl;

struct time
{
	short hour,min;
};

void normalSolution();//正常解法
void fineSolution();//比较优(没)雅(用)的解法
void perfetSolution();//优雅的解法

int main()
{
/*
	normalSolution();
	fineSolution();
	perfetSolution();
*/
	return 0;
}

void normalSolution()//正常解法
{
	int a,b,c,d,e,f;

	cin>>a>>b>>c>>d;

	e = c - a;
	f = d - b;
	if (f < 0)
	{
		f += 60;
		e--;
	}

	cout<<e<<f;
}

void fineSolution()//比较优雅的解法(有吗？明明更复杂了而已(｀ー´))
{
	time from,to,result;

	cin>>from.hour>>from.min>>to.hour>>to.min;

	result.hour = to.hour - from.hour;
	result.min = to.min - from.min;
	if (result.min < 0)
	{
		result.min += 60;
		result.hour--;
	}
	
	cout<<result.hour<<result.min;
}

void perfetSolution()//极其优雅的写法
{	
	time from,to,result;

	cin>>from.hour>>from.min>>to.hour>>to.min;
	
	//TODO:operator-

	result = to - from;
	
	cout<<result.hour<<result.min;
}
