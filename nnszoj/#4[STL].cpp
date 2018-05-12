#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::stack;

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
		while(ch[index] != '\n')
		{
			if(ch[index] == st.top())
				st.pop();
			else
				st.push(ch[index]);
			++index;
		}

		cout<<(st.empty() ? "YES" : "NO");
	}
}
