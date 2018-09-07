/*
	P1426 小鱼会有危险吗
	AC
*/

#include <iostream>

using std::cin;
using std::cout;

int main()
{
	double v = 7.0,s = 0.0;
	int a,b,c,inside = false,res;

	cin>>a>>c;

	b = a + c;//rb
	a = a - c;//lb

	while( ~(1 ^ 1) )
	{
		if(s > a)
			inside = true;
		s += v;
		if(inside)
		{
			res = s > b;
			break;
		}


		v *= 0.98;
	}

	cout<<(res ? "n" : "y");

	return 0;

}