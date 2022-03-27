#include "SLLNode.h"


class SLList
{
private:

	SLLNode *head, *tail;

public:

	SLList();
	~SLList();

	void AddToHead(HashObject k);

	void Print();
};