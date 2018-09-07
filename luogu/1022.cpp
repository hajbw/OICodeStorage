/*
	P1022 计算器的改良
*/

#include <iostream>

using std::cin;
using std::cout;

const int MAXL = 100;



int main()
{

int
	a,//temp
	neg_flag,//negative flag,set true after meeting -
	equ_flag,//negative flag,set true after meeting =
	coefficient,//coefficient of unknown
	constant;//sum up constants

char
	buf[MAXL],
	*ch,
	unknown;//name of unknown

	cin.getline(buf,MAXL);

	for(ch = buf;*ch;)
	{
		if(*ch >= '0' && *ch <= '9')
		{
			//for negatives


			//for numbers
			a = *ch - '0';
			while(*ch >= '0' && *ch <= '9')
			{
				a = (a<<1) + (a<<3) + *ch - '0';
			}
		}
	}

	return 0;
}