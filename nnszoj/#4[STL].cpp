#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::stack;

int main()
{
	char ch;
	stack<char> st;

	while(cin.get(ch))
	{
		if(ch == st.top())
			st.pop();
		else
			st.push(ch);
	}

	cout<<(st.empty() ? "YES" : "NO")
}
