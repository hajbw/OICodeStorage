#include <cstdio>
#include <cstring>

/*
	P1618 三连击（升级版）
*/

int alphabet[10];

int satisfy(int i,int n,int m)
{
	std::memset(alphabet,0,sizeof(alphabet));
	++alphabet[i/100];
	++alphabet[i/10%10];
	++alphabet[i%10];
	++alphabet[n/100];
	++alphabet[n/10%10];
	++alphabet[n%10];
	++alphabet[m/100];
	++alphabet[m/10%10];
	++alphabet[m%10];
}

int main()
{
	int A,B,C;

	std::scanf("%d %d %d",A,B,C);

	for(int i = 100;i <= 1000*A*C;++i)
		if(satisfy(i,i*B/A,i*C/A))
			std::printf("%d %d %d",i,i*B/A,i*C/A);

	return 0;
}