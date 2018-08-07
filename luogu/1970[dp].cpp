#include <iostream>

/**
	P1970 花匠
	AC
*/


#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

using std::cin;
using std::cout;

const int MAXN = 1000010;

int
	dpa[MAXN],//
	dpb[MAXN];//dpb[i] descending

int main()
{
	int n,curr,last;

	dpa[0] = dpb[0] = 1;

	cin>>n;
	cin>>last;
	for(int i = 1;i < n;++i)
	{
		cin>>curr;
		dpb[i] = curr < last ? dpa[i - 1] + 1 : dpb[i - 1];
		dpa[i] = curr > last ? dpb[i - 1] + 1 : dpa[i - 1];
		last = curr;
	}

	cout<<max(dpa[n - 1],dpb[n - 1]);

	return 0;
}
