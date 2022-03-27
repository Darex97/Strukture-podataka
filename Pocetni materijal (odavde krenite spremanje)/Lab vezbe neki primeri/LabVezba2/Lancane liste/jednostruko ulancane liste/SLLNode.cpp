#include "SLLNode.h"

SLLNode::SLLNode()
{
	link=0;
}

SLLNode::~SLLNode()
{
}

SLLNode::SLLNode(int el)
{
	this->info=el;
	link=0;
}