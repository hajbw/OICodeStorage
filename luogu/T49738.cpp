/*
	T49738 外星密码
*/
#include <iostream>
#include <stack>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::stack;
using std::string;
using std::pair;
using std::make_pair;

const int MAXL = 20010;

int main()
{
	string str,sub;
	string::iterator it,tit;
	stack<pair<int,string::iterator> > st;
	pair<int,string::iterator> top;
	int temp;

	cin>>str;
	for(it = str.begin();it != str.end();++it)
	{
		if(*it == '[')
		{
			tit = it++;
			//scan number
			temp = 0;
			while(*it >= '0' && *it <= '9')
			{
				temp = (temp<<1) + (temp<<3) + *it - '0';
				++it;
			}
			str.erase(tit,it);
			cout<<"tit:"<<*(it = tit)<<"\n";
			st.push(make_pair(temp,it));
		}
		else if(*it == ']')
		{
			top = st.top();
			cout<<"sub:"<<(sub = string(top.second,it))<<'\n';
			str.erase(top.second,it + 1);
			for(int i = 0;i < top.first;++i)
				str.insert(top.second,sub.begin(),sub.end());
		}
		cout<<"str:"<<str<<"\n";
		cout<<"it:"<<*it<<"\n";
	}

	cout<<str;

	return 0;
}
