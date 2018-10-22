/*
	P1091 合唱队形
	brute-force search
*/
#include <iostream>
#include <deque>

using std::cin;
using std::cout;
using std::deque;

const int MAXN = 105;

int arr[MAXN],N,ans = 19260817;
deque<int> quq;

void dfs(int n,int cnt)
{
	if(n > N)
	{
		deque<int>::iterator it;
		for(it = quq.begin();it != quq.end();++it)
			cout<<*it<<'\t';
		cout<<'\n';
		for(it = quq.begin();it != quq.end() - 1 && *it > *(it + 1);++it) ;
		for(;it != quq.end() - 1 && *it <= *(it + 1);++it) ;
		cout<<'\n';
		if(it == quq.end() - 1)
		{
			cout<<cnt<<'\n';
			if(cnt < ans)
				ans = cnt;
		}

		return;
	}

	dfs(n + 1,cnt + 1);
	quq.push_back(arr[n]);
	dfs(n + 1,cnt);
	quq.pop_back();
}

int main()
{
	cin>>N;
	for(int i = 1;i <= N;++i)
		cin>>arr[i];

	dfs(1,0);

	cout<<ans;

	return 0;
}