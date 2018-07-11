#include <cstdio>
#include <cstring>

/*
	P1618 三连击（升级版）
	
*/

int alphabet[20];

int satisfy(int i,int n,int m)
{
	std::memset(alphabet,0,sizeof(alphabet));
	int res = 1;
	++alphabet[i/100%10];
	++alphabet[i/10%10];
	++alphabet[i%10];
	++alphabet[n/100%10];
	++alphabet[n/10%10];
	++alphabet[n%10];
	++alphabet[m/100%10];
	++alphabet[m/10%10];
	++alphabet[m%10];
	for(int i = 1;i < 10;++i)
		if(alphabet[i] != 1)
			res = 0;
	return res;
}

int main()
{
	int A,B,C;

	std::scanf("%d %d %d",&A,&B,&C);

	for(int i = 1;i*C < 1000;++i)
		if(i*A > 100 && satisfy(i*A,i*B,i*C))
			std::printf("%d %d %d\n",i*A,i*B,i*C);

	return 0;
}