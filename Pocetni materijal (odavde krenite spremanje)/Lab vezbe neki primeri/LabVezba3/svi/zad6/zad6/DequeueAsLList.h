#include "Node.h"
class DequeueAsLList
{
	Node* head;
	Node* tail;
public:
	DequeueAsLList();
	void enqueuehead(int);
	void enqueuetail(int);
	int dequeuehead();
	int dequeuetail();
	int getinfo(){return head->getinfo();};
	bool IsEmpty(){return head==NULL;};
	void stampaj();
};