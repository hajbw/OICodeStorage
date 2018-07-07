#include <iostream>
#include <cstring>
#include <set>

/*
	P1037 产生数
*/

using std::cin;
using std::cout;
using std::set;
using std::string;

set<int> bucket[10];

int main()
{
	string n;
	int k,bit,ans = 1,x,y;

	cin>>n>>k;

	for(int i = 0;i < k;++i)
	{
		cin>>x>>y;
		if(y)
			bucket[x].insert(y);
	}

	for(string::iterator it = n.begin();i != n.end();++it)
		ans *= bucket[*it - '0'].size() + 1;

	cout<<ans;

	return 0;
}