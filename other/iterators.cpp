/*
	weird iterator implements
*/

#ifndef _HFUNC
#define _HFUNC

#include <iterator>

template<class input_t,class return_t>class hfunc_object
{
public:
	return_t operator()(input_t i);
};

template<class return_t>class hfunc_linear : hfunc_object<int,return_t>
{

public:

	return_t operator()(int i);

	class iterator : public std::iterator<std::random_access_iterator_tag,hfunc_linear<return_t>>
	{
		int x;

	public:

		iterator():x(0){}
		iterator(int start_value):x(start_value){}
		iterator(const iterator &copy){this->x = copy.x;}

		//increment/decrement implements
		iterator& operator++(){++x;return *this;}
		iterator& operator--(){--x;return *this;}
		iterator operator++(int){iterator temp(*this);++x;return temp;}
		iterator operator--(int){iterator temp(*this);--x;return temp;}
		iterator& operator+=(int i){x += i;return *this;}
		iterator& operator-=(int i){x -= i;return *this;}

		//comparisions
		bool operator==(const iterator &a)const{return x == a.x;}
		bool operator!=(const iterator &a)const{return x != a.x;}
		bool operator<(const iterator &a)const{return x < a.x;}
		bool operator>(const iterator &a)const{return x > a.x;}
		bool operator<=(const iterator &a)const{return x <= a.x;}
		bool operator>=(const iterator &a)const{return x >= a.x;}

		//dereference operators
		return_t operator*()const{return (*hfunc_linear::this)(x);}
		return_t operator[](int a)const{return (*hfunc_linear::this)(x + a);}
	};

};

#endif

/*
	使用例
*/
#include <iostream>

using std::cin;
using std::cout;


int main()
{

}