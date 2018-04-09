#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int n,i,fruit,result = 0,smallest = 0;
	vector<int>::iterator fruits_iterator;
	vector<int> fruits;

	cin>>n;

	for (i = 0; i < n; ++i)
	{
		cin>>fruit;
		fruits.push_back(fruit);
	}

	sort(fruits.begin(), fruits.end());

	while(!fruits.empty())
	{
		smallest += fruits.back();
		fruits.pop_back();
		smallest += fruits.back();
		fruits.pop_back();

		result += smallest;

		//insert "smallest" back
		fruits_iterator = fruits.end();
		while(*fruits_iterator < smallest)
			--fruits_iterator;

		fruits.insert(fruits_iterator,smallest);

		smallest = 0;
	}

	cout<<result;

	return 0;
}
