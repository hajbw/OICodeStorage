/*
	P1037 产生数
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::set;
using std::string;
using std::vector;

set<int> bucket[10];
int cnt[10];

int dfs(const int &u)
{
	if(cnt[u])
		return cnt[u];
	cnt[u] = 1;
	for(set<int>::iterator it = bucket[u].begin();it != bucket[u].end();++it)
		cnt[u] += dfs(*it);
	return cnt[u];
}

int main()
{
	string n;
	int k,ans = 1,x,y;

	cin>>n>>k;

	for(int i = 0;i < k;++i)
	{
		cin>>x>>y;
		if(y)
			bucket[x].insert(y);
	}

	for(int i = 0;i < 10;++i)
		if(!cnt[i])
			cnt[i] = dfs(i);

	for(string::iterator it = n.begin();it != n.end();++it)
		ans *= cnt[*it - '0'];

	cout<<ans;

	return 0;
}