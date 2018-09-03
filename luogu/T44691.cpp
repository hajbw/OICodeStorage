#include <iostream>

/**
	T44692 删数
*/

using std::cin;
using std::cout;
using std::endl;

const int MAXN = 1005;

unsigned long long rule[] = {1,0,1,1,0,1,0,1},rule_sum[] = {1,1,2,3,3,4,4,5};

template<class T>void read(T &x)
{
	char ch = '\0';x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
}

int main()
{
	unsigned long long q,a,b,ans;

	read(q);
	for(int i = 0;i < q;++i)
	{
		read(a);read(b);
		cout<<(rule_sum[(b - 1) & 15] - rule_sum[(a - 1) & 15] + ((b-1>>3) - (a-1>>3)) * 5ll)<<endl;
	}

	return 0;
}