#include <iostream>
#include <vector>
#include <algorithm>

/*
	P1090 合并果子
*/

using namespace std;

int main()
{
	int n,fruit,result = 0,current_heap_size = 0;
	vector<int> fruits;

	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>fruit;
		fruits.push_back(fruit);
	}

	sort(fruits.begin(), fruits.end());

	current_heap_size = fruits.back();
	fruits.pop_back();

	while(!fruits.empty())
	{
		current_heap_size += fruits.back();
		result += current_heap_size;
		fruits.pop_back();
	}

	cout<<result;

	return 0;
}