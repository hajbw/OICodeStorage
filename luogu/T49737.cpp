/*
	T49737 防护伞
*/
#include <iostream>
#include <cmath>

#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 1010;
const double Pi = 3.1415926535897932;

int main()
{
	int N,x,y;
	double rr = 0.0,temp;

	cin>>N;

	for(int i = 0;i < N;++i)
	{
		cin>>x>>y;

		temp = x * x + y * y;

		rr = max(rr,temp);
	}

	cout<<rr * Pi;

	return 0;
}
