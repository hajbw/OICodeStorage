/*
	P3370 【模板】字符串哈希
	AC
*/
#include <iostream>
#include <cstring>
#include <set>

using std::cin;
using std::cout;
using std::set;

const int MAXN = 10010,MAXM = 1536,base = 64;

char str[MAXM];

inline unsigned long long hash(char *str)
{
	int i = 0,temp;
	unsigned long long res = 0;
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

		//cout<<str[i]<<'\t'<<temp<<'\t'<<res<<'\n';

		//a << 6 == a * 64
		res = (res << 6) + temp;

		++i;
	}

	return res;
}

int main()
{
	int N;
	set<unsigned long long> strset;

	cin>>N;
	cin.getline(str,MAXN);
	for(int i = 1;i <= N;++i)
	{
		cin.getline(str,MAXN);
		//cout<<str<<'\t'<<a<<'\n';
		strset.insert(hash(str));
	}

	cout<<strset.size();

	return 0;
}