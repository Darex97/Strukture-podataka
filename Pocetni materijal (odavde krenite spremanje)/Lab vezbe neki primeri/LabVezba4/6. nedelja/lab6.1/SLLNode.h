#include "HashObject.h"

class SLLNode
{
public:

	HashObject info;
	SLLNode *link;

	SLLNode(HashObject k);
	~SLLNode();
};