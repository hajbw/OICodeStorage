/*
	P1198 [JSOI2008]最大数

	using switch to be linear / bisearched + monotone stack + handwritten stack
*/
#include <iostream>

#define BISEARCH 0

using std::cin;
using std::cout;

const int MAXM = 200020;

int M,D,t,ind;

template<class T>class hstack
{
	T *data,*head;

public:

	hstack(int siz)
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
};

template<class T1,class T2>struct hpair
{
	T1 x;
	T2 y;

	hpair():x(),y(){}
	hpair(const T1 &x,const T2 &y):x(x),y(y){}
};

template<class T1,class T2> hpair<T1,T2> hmake_pair(const T1 &x,const T2 &y)
{
	return hpair<T1,T2>(x,y);
}

hstack<hpair<int,long long> > st(MAXM);

#if BISEARCH

hpair<int,long long> *l ,*r;

inline long long query(int l)
{
	l = st.pbot();
	r = st.ptop();

	while(l - r > 1);

	return 0;
}

inline void insert(int i,long long n)
{
	return 0;
}

#else

inline long long query(int i)
//query max [i,N]
{
	hpair<int,long long> *it = st.ptop();

	while(it->x > i && it > st.pbot())
		--it;

	return it->y;
}

inline void insert(int i,long long n)
{
	while(st.top().y <= n && !st.empty())
		st.pop();

	st.push(hmake_pair(i,n));
}

#endif

int main()
{
	char q;
	int l;
	long long a;

	cin>>M>>D;
	for(int i = 1;i <= M;++i)
	{
		cin>>q;

		if(q == 'Q')
		{
			cin>>l;
			cout<<(t = query(ind - l + 1))<<'\n';
		}
		else
		{
			cin>>a;
			++ind;
			insert(ind,(a + t) % D);
		}
	}

	return 0;
}