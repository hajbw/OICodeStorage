/*
	P1156 垃圾陷阱
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXD = 105,MAXG = 105,;

struct litter
{
	int t,f,h;

	friend std::istream& operator>>(std::istream &in,litter &a)
	{
		return in>>a.t>>a.f>>a.h;
	}
}
g[MAXG];
int D,G;

int main()
{
	cin>>D>>G;
	for(int i = 1;i <= G;++i)
		cin>>g[i];

}