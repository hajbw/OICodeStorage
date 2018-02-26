#include <iostream>

using namespace std;

struct queue_node
{
	int data;
	queue_node *next;
}

class queue
{
	private:
		queue_node *head,*tail;
	public:
		queue_node* get_head()
		{
			return head;
		}
		queue_node* pop_head()
		{
		
		}
}


int main()
{

	return 0;
}
