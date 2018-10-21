/*
	hajbw stack.
	comes from linkedlist.cpp
*/
#include <iostream>

using std::cin;
using std::cout;
using std::ostream;
using std::istream;

const int MAXN = 100000;

template<class T1,class T2>struct hpair
{
	T1 x;
	T2 y;

	hpair():x(),y(){}
	hpair(const T1 &x,const T2 &y):x(x),y(y){}
};

template<class T>class hstack
{
	T *data,*head;

public:

	hstack(int siz = MAXN)
	{
		data = new T[siz];
		head = data - 1;
	}

	void push(const T &a)
	{
		*(++head) = a;
	}

	bool empty()
	{
		return head == data - 1;
	}

	T top()
	{
		return *head;
	}

	T* ptop()
	{
		return head;
	}

	T bot()
	{
		return *data;
	}

	T* pbot()
	{
		return data;
	}

	void pop()
	{
		--head;
	}

	static void printhelp(ostream &out = cout)
	{
		out<<"usage:\t[cmd] [option]\n" \
		"\tt [k]\t\t:insert k at head\n" \
		"\ta [n] [ai]*n\t:insert ai-s into head\n" \
		"\tp\t\t:pop head\n" \
		"\td [i]\t\t:delete i-th element\n" \
		"\tq\t\t:quit\n";
	}

	void printlist(ostream &out = cout)
	{
		if(empty())
		{
			cout<<"NULL\n";
			return;
		}
		T *it = head;
		cout<<*it;
		for(--it;it >= data;--it)
			cout<<" -> "<<*it;
		cout.put('\n');
	}
};

int main()
{
	char cmd;
	int a,b;
	hstack<int> hajbw;

	cout<<"hajbw lined-list demo(ans template maybe ?).\n";
	hajbw.printhelp();

	while( ~(1 ^ 1) )
	{
		hajbw.printlist();
		cout<<"> ";
		cin>>cmd;

		switch(cmd)
		{
			case 'q':
				return 0;
			break;
			case 't':
				cin>>a;
				hajbw.push(a);
			break;
			case 'a':
				cin>>a;
				while(a--)
				{
					cin>>b;
					hajbw.push(b);
				}
			break;
			case 'p':
				if(hajbw.empty())
					cout<<"fatal : stack is empty.\n";
				else
					hajbw.pop();
				break;
			case 'o' :
				if(hajbw.empty())
					cout<<"fatal : stack is empty.\n";
				else
					cout<<hajbw.top()<<'\n';
				break;
			default:
				cout<<"fatal : unreconized command.\n";
				hajbw.printhelp();
		}

	}

	return 0;
}