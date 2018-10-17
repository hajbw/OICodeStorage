/*
	P1168 中位数
*/
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::priority_queue;

const int MAXN = 100010;

int N;

priority_queue<int,std::vector<int>,std::greater<int> >	qmin;
priority_queue<int,std::vector<int>,std::less<int> >	qmax;

int main()
{
	int a;

	cin>>N;

	for(int i = 2;i <= N;++i)
	{
		cin>>a;
		qmax.push(a);
		qmin.push(a);

		if(i & 1)
		{
			qmax.pop();
			cout<<qmax.top()<<'\n';
		}
	}

	return 0;
}