#include <iostream>
#include <queue>
#include <vector>

/*
	P1090 合并果子
	AC
*/

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;

int main()
{
	priority_queue<int,vector<int>,std::greater<int>> que;
	int n,a,b,ans = 0;

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		que.push(a);
	}

	while(que.size() != 1)
	{
		a = que.top();
		que.pop();
		b = que.top();
		que.pop();
		ans += a + b;
		que.push(a + b);
	}

	cout<<ans;

	return 0;
}