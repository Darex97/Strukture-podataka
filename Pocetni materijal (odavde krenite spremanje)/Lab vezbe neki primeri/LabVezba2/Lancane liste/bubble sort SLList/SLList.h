#include "SLLNode.h"

class SLList
{
private:
	SLLNode *head,*tail;

public:

	SLList();
	~SLList();

	void AddToTail(int k);

	void Print();

	void Sort();
};