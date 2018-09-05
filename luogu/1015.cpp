#include <iostream>

#define DEBUG 1

/**
	P1015 回文数
*/

using std::cin;
using std::cout;

const int MAXN = 16,MAXM = 120;
const char bitlist[MAXN] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

int N,iM;
char M[MAXM],Mbuf[MAXM],revM[MAXM];

void readM()
{
	cin.getline(Mbuf,MAXM);
	cin.getline(Mbuf,MAXM);
	for(char *ch = Mbuf;*ch;++ch)
	{
		if(DEBUG)cout.put(*ch);
		//to number
		if(*ch >= '0' && *ch <= '9')
			*ch -= '0';
		else if(*ch >= 'A' && *ch <= 'Z')
			*ch -= 'A' + '0';
		else if(*ch >= 'a' && *ch <= 'z')
			*ch -= 'a' + '0';
		else
			continue;
		if(DEBUG)cout.put(*ch);

		M[iM++] = *ch;
	}
#if DEBUG
	cout<<Mbuf<<" ";
	for(int i = 0;i < iM;++i)
		cout<<M[i] + '0'<<'-';
	cout<<" "<<iM<<"\n\n";
#endif
}

bool verify()
{
	for(int l = 0,r = iM - 1;l < r;++l,--r)
		if(M[l] != M[r])
			return false;

	return true;
}

void opterate()
{
	int i,car;

	//copy to revM
	for(i = 0;i < iM;++i)
		revM[iM - i - 1] = M[i];

	//'add' operation
	for(i = 0;i < iM;++i)
	{
		M[i] += revM[i] + car;
		car = M[i] / N;
		M[i] %= N;
	}
	if(car)
		M[iM++] = car;
}

int main()
{
	int count = 0;

	cin>>N;
	readM();

	while(++count < 32 && verify())
		opterate();

	if(count > 30)
		cout<<"Impossible!";
	else
		cout<<"STEP="<<count;

	return 0;
}