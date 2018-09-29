/*
	P1067 多项式输出
	AC
*/
#include <iostream>

using namespace std;

int main()
{
	int a,n;
	
	cin>>n;
	
	for(int i = n;i > -1;--i)
	{
		cin>>a;
		
		if(!a)
			continue;
		
		if(a == -1 && i != 0)
		{
			cout.put('-');
			goto outx;
		}
		
		if(a > 0 && i < n)
			cout.put('+');
			
		if(a != 1 || i == 0)
			cout<<a;
		
outx:
			
		if(i == 1)
			cout.put('x');
		else if(i)
			cout<<"x^"<<i;
			
		//to debug
		//cout<<'\t'<<i<<endl;
	}

	return 0;
}