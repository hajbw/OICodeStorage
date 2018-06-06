#include <iostream>
#include <stack>

/*
	#4. 括号匹配
*/

using std::cin;
using std::cout;
using std::stack;

inline bool match(char &l,char &r)
{
	return 
		('(' == l && ')' == r) ||
		('[' == l && ']' == r) ||
		('{' == l && '}' == r) ;
}

int main()
{
	char ch[100];
	stack<char> st;
	int n,index;

	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		index = 0;
		cin.getline(ch);
		while(ch[index])
		{
			if(match(st.top(),ch[index]))
				st.pop();
			else
				st.push(ch[index]);
			++index;
		}

		cout<<(st.empty() ? "YES" : "NO");
	}
}
