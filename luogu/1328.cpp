/*
	P1328 生活大爆炸版石头剪刀布
	AC
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 205;

int N,Na,Nb,arr[MAXN],brr[MAXN],resa,resb,score[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};

int main()
{
	int a;

	cin>>N>>Na>>Nb;
	for(int i = 0;i < Na;++i)
		cin>>arr[i];
	for(int i = 0;i < Nb;++i)
		cin>>brr[i];

	for(int i = 0;i < N;++i)
	{
		resa += score[arr[i % Na]][brr[i % Nb]];
		resb += score[brr[i % Nb]][arr[i % Na]];
	}

	cout<<resa<<' '<<resb;

	return 0;
}