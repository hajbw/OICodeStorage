#include <iostream>
#include <cstring>

/**
	LIS
*/

using std::cin;
using std::cout;

const int MAXN = 10100;

int arr[MAXN],sub[MAXN],isub;

int bisearch(int val)
{
	if(val < sub[0])
		return -1;
	if(val > sub[isub])
}

template<class T> void read(std::istream &in,T &x)
{
	char ch = '\0';int flag = 0;x = 0;in.get(ch);
	while(ch < '0' || ch > '9')		{flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9')	{x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

int main()
{
	int n,index;

	std::memset(arr,63,sizeof(arr));

	read(cin,n);
	for(int i = 0;i < n;++i)
		read(cin,arr[i]);

	for(int i = 0;i < n;++i)
	{
		index = bisearch(arr[i]);
		if(index == -1)
			continue;

	}

	return 0;

}