/*
	P1618 三连击（升级版）
	AC
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int alphabet[20];

inline int min3(const int &a,const int &b,const int &c)
{
	int res = a;
	if(b > res)res = b;
	if(c > res)res = c;
	return res;
}

inline int max3(const int &a,const int &b,const int &c)
{
	int res = a;
	if(b < res)res = b;
	if(c < res)res = c;
	return res;
}

bool satisfy(const int &i,const int &n,const int &m)
{
	for(int a = 0;a < 10;++a)
		alphabet[a] = 0;

	++alphabet[i/100];
	++alphabet[i/10%10];
	++alphabet[i%10];
	++alphabet[n/100];
	++alphabet[n/10%10];
	++alphabet[n%10];
	++alphabet[m/100];
	++alphabet[m/10%10];
	++alphabet[m%10];

	for(int i = 1;i < 10;++i)
		if(alphabet[i] != 1)
			return false;

	return true;
}

int main()
{
	int A,B,C,nmin,nmax,flag = 0;

	cin>>A>>B>>C;

	nmin = min3(A,B,C);
	nmax = max3(A,B,C);

	for(int i = 100 / nmin;i * nmax < 988;++i)
		if(satisfy(i * A,i * B,i * C))
			cout<<i * A<<" "<<i * B<<" "<<i * C<<" \n",flag = 1;

	if(!flag)cout<<"No!!!";

	return 0;
}