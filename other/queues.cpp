//queue

template<class T>class hdeque
{
	struct node
	{
		T& data;
		node *prev,*next;

		node(){}
		node(T &d,node *p,node *n):data(d),prev(p),next(n){}
	};

	node head,tail,*temp;
	int size_;

public:

	hdeque()
	{
		head.next = &tail;
		tail.prev = &head;
		size_ = 0;
	}

	T& front()
	{
		return *head.next;
	}

	T& back()
	{
		return *tail.prev;
	}

	void push_front(T &val)
	{
		temp = new node(val,&head,head.next);
		head.next = temp;
		temp->next->prev = temp;
		++size_;
	}

	void push_back(T &val)
	{
		temp = new node(val,tail.prev,&tail);
		tail.prev = temp;
		temp->prev->next = temp;
		++size_;
	}

	void pop_front()
	{
		if(head.next == &tail)
			return;
		temp = head.next;
		head.next = temp->next;
		temp->next->prev = &head;
		delete temp;
		--size_;
	}

	void pop_back()
	{
		if(tail.prev == &head)
			return;
		temp = tail.prev;
		tail.prev = temp->prev;
		temp->prev->next = &tail;
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
	
};

int main()
{
	return 0;
}