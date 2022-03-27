#include "Node.h"
class QueueAsLList
{
	Node* head;
	Node* tail;
public:
	QueueAsLList();
	void enqueue(int);
	int dequeue();
	int getinfo(){return head->getinfo();};
	bool IsEmpty(){return head==NULL;};
	void stampaj();
};