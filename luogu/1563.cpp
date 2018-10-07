#include <iostream>
#include <string>

#define calc(f1,f2) (f1 ^ f2 ? 1 : -1)

/**
	P1563 玩具谜题
	AC
*/

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int MAXM = 100010,MAXN = 200010;

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
		cin>>toys[i].face>>toys[i].name;

	for(int i = 0;i < m;++i)
	{
		cin>>face>>amount;
		index = (index + calc(toys[index].face,face) * amount) % n;
		if(index < 0)
			index += n;
	}

	cout<<toys[index].name;

	return 0;
}
