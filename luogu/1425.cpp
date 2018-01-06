#include <iostream>

/*
	P1425 小鱼的游泳时间
	已AC(但是我就是要写题解！)
*/

using std::cin;
using std::cout;
using std::endl;

int main()
{

	//正常解法

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

	//End 正常解法
/*
	//优雅解法
	struct time
	{
		short hour,min;
	};

	time from,to,result;

	cin>>from.hour>>from.min>>to.hour>>to.min;

	//比较优雅的解法(有吗？明明更复杂了而已(｀ー´))

	result.hour = to.hour - from.hour;
	result.min = to.min - from.min;
	if (result.min < 0)
	{
		result.min += 60;
		result.hour--;
	}

	//End比较优雅的解法

	//非常优雅的解法

	//TODO:operator-

	result = to - from;

	//End 非常优雅的解法

	cout<<result.hour<<result.min;

	//End 优雅解法
*/
	return 0;
}
