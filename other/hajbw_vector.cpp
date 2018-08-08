
/**
	this won't run for having no main() function
	only a template 
*/

#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

#ifndef _GLIBCXX_CSTRING
#include <cstring>
#endif

class hajbw_vector_array
{
public:

	static const int MAXN = 1000;

private:

	int arr[MAXN];
	int front,back;

public:

	hajbw_vector_array():front(0),back(0)
	{
		std::memset(arr,0,sizeof(arr));
	}

	void push(int i)
	{
		arr[back] = i;
		++back;
		if(back == MAXN)
			back = 0;
	}

	int pop()
	{
		int i = arr[front];
		++front;
		if(front == MAXN)
			front = 0;
		return i;
	}

	int front()
	{
		return arr[front];
	}

	int back()
	{
		return arr[back];
	}

	int operator[](int i)
	{
		i = (i + front) % MAXN;
		return arr[i];
	}

};

template<class T> class hajbw_vector_linked_list
{

public:

	struct node
	{
		
	};

	hajbw_vector_linked_list()
	{

	}

};
