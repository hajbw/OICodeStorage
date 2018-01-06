#include <iostream>

/*
	P1003 铺地毯
*/

using std::cin;

struct carpet
{
	int x,y,width,height;
}

int main()
{
	int amountOfCarpet,targetX,targetY,result;
	carpet * carpets;
    
	cin>>amountOfCarpet;
    
	carpets = new carpet[amountOfCarpet];

	for (int i = 0; i < amountOfCarpet; ++i)
		cin>>carpets[i].x>>carpets[i].y>>carpets[i].width>>carpets[i].height;

	for (result = amountOfCarpet; result > 0 ; result)
	{
		
	}

	cout<<result;

	delete [] carpet;

	return 0;
}