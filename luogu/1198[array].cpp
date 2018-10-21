/*
	P1198 [JSOI2008]最大数

	using bisearch + monotone stack + naked array
*/
#include <iostream>
#include <algorithm>

#define USE_STL 1

using std::cin;
using std::cout;

const int MAXM = 200010,INF = 2147483647;

int order[MAXM],val[MAXM] = {INF},head = 1,ind,M,D,t;

//note:
//	make val[0] = INF
//	to make whole decreasing
//	bisearch to query and modify
//	the bisearch is lower_bound
//
//	head:last(smallest) element in stack

#if USE_STL

std::less<int> rev_cmp;

inline int query(int i)
{
	if(head == 1)
		return 0;
	return val[std::lower_bound(order,order + head + 1,i) - order];
}

inline void insert(int i,int n)
{
	head = std::lower_bound(val,val + head + 1,n) - val;
	order[head] = i;
	val[head] = n;
}

#else

inline int query(int i)
{
	int l = 0,r = head,mid;//range : (l,r]
	while()
}

inline void insert(int i,int n)
{

}

#endif

int main()
{
	char cmd;
	int l;
	long long n;

	cin>>M>>D;
	for(int i = 0;i < M;++i)
	{
		cin>>cmd;
		if(cmd == 'Q')
		{
			cin>>l;
			cout<<(t == query(ind - l + 1))<<'\n';
		}
		else
		{
			cin>>n;
			++ind;
			insert(ind,(n + t) % D);
		}

		cout<<"\n------------------------------\n"<<head<<'\n';
		for(int i = 0;i <= head;++i)
			cout<<order[i]<<'\t';
		cout<<'\n';
		for(int i = 0;i <= head;++i)
			cout<<
	}

	return 0;
}