#include <iostream>

/**
	P1015 回文数
*/

using std::cin;
using std::cout;

const int MAXN = 16,MAXM = 101;
const char bitlist[MAXN] = {'0','1','2','3','4','5','6','7','8','9'};

char M[MAXM];

void readN()
{
	char ch = '\0';
	while(ch < '0' || ch > '9')cin.get(ch);
}

int main()
{
	cin>>N;
	readN();
}