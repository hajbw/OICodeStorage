#include <iostream>

/**
	P1970 花匠
*/

using std::cin;
using std::cout;

int main()
{
	int n,curr,ans = 1,last,flag = 0;//0:up

	cin>>n;
	cin>>last;

	for(int i = 1;i < n;++i)
	{
		cin>>curr;
		if(curr != last && ((curr < last) == flag))
		{
			++ans;
			flag ^= 1;
		}

		last = curr;
	}

	cout<<ans;

	return 0;
}
