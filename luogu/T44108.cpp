#include <iostream>

/**
	T44108 大凯的疑惑

	fact:4n ^ 4n+1 ^ 4n+2 ^ 4n+3 == 0
*/

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n,l,r,ans = 0;

	cin>>n;
	for(int i = 0;i < n;++i)
	{
		cin>>l>>r;

		//if(r - l < 8)
		{
			for(;l <= r;++l)
				ans ^= l;
			continue;
		}

		/*
		for(;l % 4;++l)
			ans ^= l;
		for(;r % 4;--r)
			ans ^= r;
		//*/
	}

	cout<<ans<<endl;

	return 0;
}