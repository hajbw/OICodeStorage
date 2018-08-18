//queue

template<class T>class hqueue
{

public:

	struct node
	{
		T data;
		node* next;

		node():data(),next(){}
		node(T data):data(data),next(){}
		node(T data,node* next):data(data),next(){}
 	};

	hqueue();

	bool empty();
	int size();
	T front();
	T back();
	void push();
	void pop();
}

template<class T>class hdeque
{

public:

	struct node
	{
		T data;
		node* prev,next;
	};

	hdeque();

	bool empty();
	int size();
	void push_front();
	void push_back();
	T pop_front();
	T pop_back();
}