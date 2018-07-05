#include <iostream>
#include <set>

/*
	P1037 产生数
*/

using std::cin;
using std::cout;
using std::set;

typedef unsigned long long num;

int main()
{
	num n;
	int k,bit,ans = 1,x,y;
	set<int> bucket[10];

	cin>>n>>k;

	for(int i = 0;i < k;++i)
	{
		cin>>x>>y;
		if(y)
			bucket[x].insert(y);
	}

	while(n != 0)
	{
		bit = n % 10;
		ans *= bucket[bit].size() + 1;
		n /= 10;
	}

	cout<<ans;

	return 0;
}