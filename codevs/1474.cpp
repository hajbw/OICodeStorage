#include <iostream>

/**
	*1474 十进制转m进制

	*题目描述 Description
	*将十进制数n转换成m进制数
	*m<=16 n<=100

	*已AC
*/

using std::cin;
using std::cout;
using std::endl;

int main()
{
	const char mapping[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	const char flag_stop = 32;
	int n,m,index = 0;
	char res[8] = {flag_stop,flag_stop,flag_stop,flag_stop,flag_stop,flag_stop,flag_stop,flag_stop};

	cin>>n>>m;

	do
	{
		res[index] = n % m;
		index++;
	}
	while(n /= m);

	while(index--&&res[index]!=flag_stop)
		cout.put(mapping[res[index]]);

	return 0;
}
