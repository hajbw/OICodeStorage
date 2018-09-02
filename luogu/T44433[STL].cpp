#include <iostream>
#include <string>
#include <set>

/**
	T44433 生日
	using std::set
*/

using std::cin;
using std::cout;
using std::string;
using std::set;
using std::pair;
using std::make_pair;

const int MAXY = 100,MAXM = 13,MAXD = 32;

set<pair<int,string>> date[1300];

void insert(string &name,const int &y,const int &d)
/**
	insert descendingly
*/
{
	date[d].insert(make_pair(y,name));
}

string query(int k,int s)
{
	--k;
	set<pair<int,string>>::iterator it = date[s].begin();
	while(k)
	{
		++it;
		--k;
	}
	return it->second;
}

int main()
{
	int m,n,date,k,s;
	string name;

	cin>>n>>m;

	for(int i = 0;i < n;++i)
	{
		cin>>name>>date;
		insert(name,date / 1000,date % 1000);
	}

	for(int i = 0;i < m;++i)
	{
		cin>>k>>s;
		cout<<query(k,s)<<std::endl;
	}

	//system("pause");

	return 0;
}
