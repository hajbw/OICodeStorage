#include <iostream>
#include <cstring>

using namespace std;

/*
	P2014 选课
*/

int value[310],f[310][310],son[310] {0},next[310],m,n;

int main()
{
	//I'm not sure if f[][]{0} works
	memset(f,0,sizeof(f));
	//input and build
	cin>>n>>m;

	int father;
	for (int i = 1; i <= n; ++i)
	{
		cin>>father>>value[i];
		next[i] = son[father];
		son[father] = i;
	}

	return 0;
}

