#include "HashObject.h"

class SLLNode  
{
public:
	HashObject info;
	SLLNode *next;
public:
	SLLNode();
	
	SLLNode(HashObject& i);
	
	SLLNode(HashObject& i, SLLNode* n);
	
	~SLLNode(){};
	
	HashObject Prin )
	{
		return info;
	}
	
	bool IsEqual(HashObject& el)
	{ 
		return el.record == info.record;
	}
};