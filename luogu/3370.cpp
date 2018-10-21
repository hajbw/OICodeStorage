/*
	P3370 【模板】字符串哈希
*/
#include <iostream>
#include <cstring>
#include <set>

using std::cin;
using std::cout;
using std::set;

const int MAXN = 10010,MAXM = 1536,P = 1000000007,base = 64;

char str[MAXM];

inline int hash(char *str)
{
	int i = 0,temp;
	long long res;
	while(str[i])
	{
		//mapping:
		//	'0'(48) -> 1
		//	'a'(97) -> 11
		//	'A'(65) -> 37

		if(str[i] >= 'a')
			temp = str[i] - 'a' + 11;
		else if(str[i] >= 'A')
			temp = str[i] - 'A' + 37;
		else
			temp = str[i] - '0' + 1;

		hars[i] = 
	}

}

int main()
{
	cin>>N;
	for(int i = 1;i <= N;++i)
	{
		cin.getline(str,MAXN);
		hash(str)
	}
}