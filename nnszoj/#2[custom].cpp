#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 100000;

int arr[MAXN];

int main()
{
	int i = 0,n,k,
	low = 0,high,mid;//indexes
	cin>>n;
	for(;i < n;++i)
		cin>>arr[i];
	cin>>k;
	
	high = n;
	mid = (low + high + 1)/2;
	
	while(arr[mid] != k)
	{
		if(k > arr[mid])
			low = mid;
		else
			high = mid;
		if(low + 1 == high)
		{
			cout<<-1;
			return 0;
		}
		mid = (low + high + 1)/2;
	}
	
	cout<<mid;
	
	return 0;
}