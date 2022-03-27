#include "DLLNode.h"

class DLList
{
private:
	DLLNode *head,*tail;

public:

	DLList();
	~DLList();

	void AddToTail(int el);
	void AddToHead(int el);

	void Print();

	int DeleteFromTail();
	int DeleteFromHead();
	void DeleteElement(int el);

	void IsInList(int el);

	void DeleteAll();

	int NumberOfNodes();
};

