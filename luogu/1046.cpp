#include <iostream>

/*
	P1046 陶陶摘苹果
	已AC
*/

using std::cin;
using std::cout;

int main()
{
	int apples[10],height,result = 0;

	for (int i = 0; i < 10; ++i)
		cin>>apples[i];

	cin>>height;

	height += 30;

	for (int i = 0; i < 10; ++i)
		if(height >= apples[i])
			++result;

	cout<<result;

	return 0;
}