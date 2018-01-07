#include <iostream>

/*
	P1003 铺地毯
*/

using std::cin;

struct carpet
{
	int x,y,width,height;
}

bool isInside(int,int,carpet);

int main()
{
	int amountOfCarpet,targetX,targetY,result;
	carpet * carpets;

	cin>>amountOfCarpet;

	carpets = new carpet[amountOfCarpet];

	for (int i = 0; i < amountOfCarpet; ++i)
		cin>>carpets[i].x>>carpets[i].y>>carpets[i].width>>carpets[i].height;

	for (result = amountOfCarpet; result > 0 ; result)
		//result - 1 to access carpets[index]
		if(isInside(targetX,targetY,carpets[result]))
			break;

	if(result = 0)
		result = -1;//ugly fix

	std::cout<<result;

	delete [] carpets;

	return 0;
}

bool isInside(int x,int y,carpet cover)
{
	return x >= cover.x && x <= cover.x + cover.width && y >= cover.y && y <= cover.y + cover.height;
}