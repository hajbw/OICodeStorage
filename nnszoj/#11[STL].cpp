#include <iostream>
#include <queue>

/*
	有n（<=100）个硬币正面朝上，每次能且仅能将m(m<=n)个硬币翻转。
	请问至少要用多少次，可以将全部硬币翻转成背面朝上的状态。
*/

using std::cin;
using std::cout;
using std::queue;

int main()
{
	int n,m,curr,curr_layer,low,high;
	queue<int> que,layer;

	cin>>n>>m;

	que.push(n);
	layer.push(0);

	while(!que.empty())
	{
		curr = que.front();
		que.pop();
		curr_layer = layer.front() + 1;
		layer.pop();
		low = curr - m > 0 ? curr - m : m - curr;
		high = curr + m > n ? cirr + m : n - m -curr; 
		for (int i = low; i <= high; i += 2)
		{
			if(i = 0)
			{
				cout<<curr_layer;
				return 0;
			}
			que.push(i);
			layer.push(curr_layer);
		}
	}

}
