/*
	mod.cpp:damage.cpp tester
*/

#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int a,b,p,ans1,ans2;

	cin>>a>>b>>p;

	for(int i = a;i <= b;++i)
		if(!(i % p))
			++ans1;

	ans2 = (b - a + 1) / p;

	if(!((b - a) % p) && !(a % p))
		++ans2;

	cout<<ans1<<'\t'<<ans2;

	return 0;
}