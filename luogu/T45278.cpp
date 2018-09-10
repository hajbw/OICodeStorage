/*
	T45278 符文之语(chars. pas/c/cpp)
*/

#include <iostream>

using std::cin;
using std::cout;

const int MAXL = 1005,MAXM = 50;

char str[MAXL];
int m,index;

int mod()
{
	
}

int main()
{
	cin.getline(str,MAXL);
	for(index = 0;str[index];++index)
		str[index] -= '0';
	cin>>m;
}