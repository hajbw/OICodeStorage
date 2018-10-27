#include <iostream>

/**
	number generator
	generates N lines M columns of data
*/

using namespace std;

int main(int argc, char const *argv[])
{
	int M = 0,N = 0,lower_bound = 0,higer_bound = 0,a;

	if(argc == 1)
	{
		cerr<<"input M,N,lower_bound,higer_bound :\n";
		cin>>M>>N>>lower_bound>>higer_bound;
	}
	else
	{
		for(const char *ch = argv[1];*ch >= '0' && *ch <= '9';++ch)
			M = (M<<1) + (M<<3) + *ch - '0';
		for(const char *ch = argv[2];*ch >= '0' && *ch <= '9';++ch)
			N = (N<<1) + (N<<3) + *ch - '0';
		for(const char *ch = argv[3];*ch >= '0' && *ch <= '9';++ch)
			lower_bound = (lower_bound<<1) + (lower_bound<<3) + *ch - '0';
		for(const char *ch = argv[4];*ch >= '0' && *ch <= '9';++ch)
			higer_bound = (higer_bound<<1) + (higer_bound<<3) + *ch - '0';
	}

	a = higer_bound - lower_bound + 1;

	cout<<N<<' '<<M<<'\n';

	for(int i = 0;i < N;++i)
	{
		for(int j = 0;j < M;++j)
		{
			cout<<rand() % a + lower_bound<<" ";
		}
		cout<<endl;
	}

	return 0;
}