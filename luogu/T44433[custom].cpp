#include <iostream>
#include <string>

/**
	T44433 生日
*/

using std::cin;
using std::cout;
using std::string;

const int MAXY = 100,MAXM = 13,MAXD = 32;

struct person
{
	string name;
	int year;
	person *next;

	person():name(),year(),next(){}
	person(string &n,int &y):name(n),year(y),next(){}
	person(string &n,int &y,person *ne):name(n),year(y),next(ne){}
}
*date[1300];

void insert(string &name,int y,int d)
/**
	insert descendingly
*/
{
	person 
		*p = new person(name,y),
		**temp = &date[d];

	while((*temp) && (*temp)->year > p->year)
		temp = &(*temp)->next;

	p->next = *temp;
	*temp = p;
}

string& query(int k,int s)
{
	--k;
	person *it = date[s];
	while(k && it->next)
	{
		it = it->next;
		--k;
	}
	return it->name;
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
		cout<<query(k,s);
	}

	return 0;
}