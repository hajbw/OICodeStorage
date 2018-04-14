#include <iostream>
#include <cstring>

/*
	P1073 最优贸易
*/

using namespace std;

const int MAX_V = 100000 ,MAX_E = 500000;

int Vcount,Ecount,
	x,y,z,e = 0,result = 0,
	gruaph[MAX_E * 2][2],
	prize[MAX_V],buy[MAX_V],sell[MAX_V];


int main()
{
	
	//input
	cin>>Vcount>>Ecount;
	for (int i = 0; i < Vcount; ++i)
		cin>>prize[i];
	for (int i = 0; i < Ecount; ++i)
	{
		cin>>x>>y>>z;
		++e;
		gruaph[e][0] = x;
		gruaph[e][1] = y;
		if(z == 2)
		{
			++e;
			gruaph[e][0] = y;
			gruaph[e][1] = x;
		}
	}

	for (int i = 0; i < Vcount; ++i)
		sell[i] = buy[i] = prize[i];

	for (int i = 0; i < Vcount; ++i)
	{
		for (int j = 0; j < e; ++j)
		{
			if(buy[gruaph[j][1]] > buy[gruaph[j][0]])
				buy[gruaph[j][1]] = buy[gruaph[j][0]];
			if(sell[gruaph[j][1]] < sell[gruaph[j][0]])
				sell[gruaph[j][1]] = sell[gruaph[j][0]];
		}
	}
/*
	for (int i = 0; i < Vcount; ++i)
	{
		for (int j = 0; j < e; ++j)
			if(sell[gruaph[j][1]] < sell[gruaph[j][0]])
				sell[gruaph[j][1]] = sell[gruaph[j][0]];
	}
*/
	//output
	for (int i = 0; i < e; ++i)
	{
		e = sell[i] - buy[i];
		result = e > result ? e : result;
	}
	cout<<result;

	return 0;
}
