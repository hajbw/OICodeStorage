/*
	P1198 [JSOI2008]最大数

	using bisearch + monotone stack + naked array

	aaaaahahhhhhhhhaaaaaaa!!!!!!!I did itttttttttttttt!!!!!

	both STL enabled and disabled works 
*/
#include <iostream>
#include <algorithm>

#define USE_STL 1
#define DEBUG 0

using std::cin;
using std::cout;

const int MAXM = 200010,INF = 2147483647;

int order[MAXM],val[MAXM] = {INF},head,ind,M,D,t;

//note:
//	make val[0] = INF
//	to make whole decreasing
//	bisearch to query and modify
//	the bisearch is lower_bound
//
//	head:last(smallest) element in stack

#if USE_STL

std::greater<int> rev_cmp;

inline int query(int i)
{
	return val[std::lower_bound(order,order + head + 1,i) - order];
}

inline void insert(int i,int n)
{
	head = std::lower_bound(val,val + head + 1,n,rev_cmp) - val;
	order[head] = i;
	val[head] = n;
}

#else

inline int query(int i)
{
	//note :
	//range : (l,r]
	//make order[r] >= a,order[l] < a
	int l = 0,r = head,mid;
	while(r - l > 1)
	{
		mid = l + r >> 1;

		if(order[mid] >= i)
			r = mid;
		else
			l = mid;
	}
	return val[r];
}

inline void insert(int i,int n)
{
	if(n < val[head])
	{
		++head;
		order[head] = i;
		val[head] = n;
		return;
	}

	int l = 0,r = head,mid;

	while(r - l > 1)
	{
		mid = l + r >> 1;

		if(val[mid] > n)
			l = mid;
		else
			r = mid;
	}

	head = r;
	order[head] = i;
	val[head] = n;
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
			cout<<(t = query(ind - l + 1))<<'\n';
		}
		else
		{
			cin>>n;
			++ind;
			insert(ind,(n + t) % D);
		}

#if DEBUG

		cout<<"\n------------------------------\n"<<head<<'\n';
		for(int i = 0;i <= head;++i)
			cout<<order[i]<<'\t';
		cout<<'\n';
		for(int i = 0;i <= head;++i)
			cout<<(val[i] >= INF ? -1 : val[i])<<'\t';
		cout<<'\n';

#endif
	}

	return 0;
}