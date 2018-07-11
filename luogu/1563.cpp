#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

const int MAXM = 100005,MAXN = 100005;

struct toy
{
	int face;
	string name;
}
toys[MAXN];

int main()
{
	int m,n,index = 0,face,amount;

	cin>>n>>m;

	for(int i = 0;i < n;++i)
		cin>>toys[i].revert>>toys[i].name;

	for(int i = 0;i < m;++i)
	{
		cin>>face>>amount;
		//TODO
		index = (toys[index].face ^ face)
	}

}