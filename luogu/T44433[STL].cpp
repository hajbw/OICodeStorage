#include <iostream>
#include <string>
#include <set>

/**
	T44433 生日
*/

using std::cin;
using std::cout;
using std::string;
using std::set;

const int MAXY = 100,MAXM = 13,MAXD = 32;

struct person
{
	string name;
	int year;
	person *next;

	person():name(),year(),next(){}
	person(string &n,int &y):name(n),year(y),next(){}
	person(string &n,int &y,person *ne):name(n),year(y),next(ne){}
};

void insert(person &p,const int &d)
/**
	insert descendingly
*/
{
	
}

string& query(int k,int s)
{
	
}

int main()
{
	int m,n,date,k,s;
	string name;

	cin>>n>>m;

	for(int i = 0;i < n;++i)
	{
		cin>>name>>date;
		insert(new person(name,date/1000),date%1000);
	}

	for(int i = 0;i < m;++j)
	{
		cin>>k>>s;
		cout<<query(k,s);
	}

	return 0;
}