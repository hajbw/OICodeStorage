#include <iostream>

using std::cin;
using std::cout;

template<class T>class hdeque
{
	struct node
	{
		T& data;
		node *prev,*next;

		node():data(),prev(),next(){}
		node(T &d,node *p,node *n):data(d),prev(p),next(n){}
	};

	node *head,*tail,*temp;
	size_t size_;

public:

	hdeque()
	{
		head = tail = NULL;
		size_ = 0;
	}

	T& front()
	{
		return head->data;
	}

	T& back()
	{
		return tail->data;
	}

	void push_front(T &val)
	{
		head = new node(val,NULL,head);
		if(!tail)
		++size_;
	}

	void push_back(T &val)
	{
		tail = new node(val,tail,NULL);
		++size_;
	}

	void pop_front()
	{
		if(!head)
			return;
		temp = head;
		head = head->next;
		delete temp;
		--size_;
	}

	void pop_back()
	{
		if(!tail)
			return;
		temp = tail;
		tail = tail->prev;
		delete temp;
		--size_;
	}

	int size()
	{
		return size_;
	}

	bool empty()
	{
		return !size_;
	}

	friend std::ostream& operator<<(std::ostream &out,const hdeque &quq)
	{
		for(node *ptr = quq.head;ptr;ptr = ptr->next)
			cout<<ptr->data;
		return out;
	}
	
};


int main()
{

	return 0;
}