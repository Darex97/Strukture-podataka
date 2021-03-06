#include "SLLNode.h"

class SLList  
{
protected:
	SLLNode *head,*tail;
public:

	SLList()
	{
		head = tail = 0;
	}

	~SLList()
	{
	}

	bool IsEmpty()
	{ 
		return head==0;
	}
	
	void AddToHead(HashOb ct& el);
	
	void AddToTail(HashObject& el);
	
	HashObject DeleteFromHead();
	
	HashObject DeleteFromTail();
	
	SLLNode* FindNodePtr(HashObject& el);

	SLLNode* GetHead()
	{ 
		return head;
	}

	SLLNode* GetNext(SLLNode *ptr);

	HashObject GetHeadEl();

	HashObject GetNextEl(HashObject& el);

	void PrintAll();

	bool IsInList(HashObject& el);

	void DeleteEl(HashObject& el);
};

