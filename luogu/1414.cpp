#include <iostream>
#include <cmath>

/*
	P1414 又是毕业季II
*/

using std::cin;
using std::cout;
using std::endl;

const int MAXN = 10001,INF = 1000010;

//  做因子的次数
int factor[INF];

int main()
{
	int n,ability,gnr,i,j;

	cin>>n;

	for(i = 0;i < n;++i)
	{
		cin>>ability;

		gnr = int(std::sqrt(ability));
		
		for(j = 0;j <= gnr;++j)
			if(!(ability % j))
			{
				++factor[j];
				if(j * j != ability)
					++factor[ability/j];
			}
	}

	j = ability;

	for(i = 1;i <= n;++i)
	{
		while(factor[j] < i) --j;
		cout<<j<<endl;
	}

	return 0;
}