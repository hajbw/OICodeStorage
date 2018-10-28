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

	bool available(input_t i)const; 
};

template<class return_t>class hfunc_linear : hfunc_object<int,return_t>
{
	input_t min_val,max_val;

public:

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
		iterator operator++(int){iterator tmp(*this);++x;return tmp;}
		iterator operator--(int){iterator tmp(*this);--x;return tmp;}
		iterator& operator+=(int i){x += i;return *this;}
		iterator& operator-=(int i){x -= i;return *this;}

		//numberic operations
		iterator operator+(int i){iterator res(*this);return ++res;}


		//comparisions
		bool operator==(const iterator &a)const{return x == a.x;}
		bool operator!=(const iterator &a)const{return x != a.x;}
		bool operator<(const iterator &a)const{return x < a.x;}
		bool operator>(const iterator &a)const{return x > a.x;}
		bool operator<=(const iterator &a)const{return x <= a.x;}
		bool operator>=(const iterator &a)const{return x >= a.x;}

		//dereference operators
		return_t operator*()const{;return (*hfunc_linear::this)(x);}
		return_t operator[](int a)const{return (*hfunc_linear::this)(x + a);}
	};

	return_t operator()(int i);

	bool available(input_t i)const
	{
		return i <= max_val && i > min_val;
	}

	iterator begin(){return iterator(min_val);}

	iterator end(){return iterator(max_val + 1);}

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