#include "SLLNode.h"

SLLNode::SLLNode()
{
	next = 0;
}
	
SLLNode::SLLNode(HashObject& i)
{
	info = i; 
	next = 0;
}
	
SLLNode::SLLNode(HashObject& i, SLLNode* n)
{
	info = i;
	next = n;
}
	
SLLNode::~SL ode();