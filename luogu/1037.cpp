#include <iostream>
#include <set>

/*
	P1037 产生数
*/

using std::cin;
using std::cout;
using std::set;

typedef unsigned long long num;

set<int> bucket[10];
int visited[10];

void DFS(int i)
{
	for(set<int>::iterator it = bucket[i].begin();it != bucket[i].end();++it)
		DFS(*it);
}

int main()
{
	num n;
	int k,bit,ans = 1,x,y;

	cin>>n>>k;

	for(int i = 0;i < k;++i)
	{
		cin>>x>>y;
		if(y)
			bucket[x].insert(y);
	}

	//DFS&union bucket


	while(n != 0)
	{
		bit = n % 10;
		ans *= bucket[bit].size() + 1;
		n /= 10;
	}

	cout<<ans;

	return 0;
}