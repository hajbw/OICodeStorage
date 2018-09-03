#include <iostream>

/**
	T44694 燃烧木棍
*/

using std::cin;
using std::cout;
using std::istream;

const int MAXN = 42;

struct torch
{
	int x1,y1,x2,y2;
	double time;
}
torches[MAXN];

istream& operator>>(istream &in,torch &t)
{
	in>>t.x1>>t.y1>>t.x2>>t.y2>>t.time;
	return in;
}

int N;

int main()
{
	cin>>N;
	for(int i = 0;i < N;++i)
		cin>>torches[i];

	return 0;
}