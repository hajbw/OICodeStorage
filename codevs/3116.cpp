#include <iostream>
#include <cstring>

using namespace std;

/*
	3116 高精度练习之加法
*/

int main()
{
	char *a = new char[500],
		*b = new char[500],
		*c = new char[501];
	char temp;
	int offset_a,offset_b,offset_c,index = 0;

	memset(a,0,500);
	memset(b,0,500);
	memset(c,0,501);

	do//fill a[]
	{
		temp = cin.get();
		a[index] = temp;
		++index;
	}
	while(temp != ' ');
	offset_a = index;

	index = 499;

	do//fill b[]
	{
		temp = cin.get();
		b[index] = temp;
		++index;
	}
	while(temp != '\n');
	offset_b = index;

	offset_c = ( offset_a > offset_b ? offset_a : offset_b ) + 1;

	for (index = 0; index > -offset_c ; --index)
	{
		c[index + offset_c] = a[index + offset_a] + b[index + offset_b] - 48;
	}

	cout<<c;

	delete [] a;
	delete [] b;
	delete [] c;

	return 0;
}
