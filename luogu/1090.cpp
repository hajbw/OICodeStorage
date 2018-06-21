#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;

int main()
{
	priority_queue<int,vector<int>,std::greater<int>> que;
	int n,temp;

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		que.push(temp);
	}

	while(que.size() != 1)
	{
		
	}

}