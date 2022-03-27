#include "DLLNode.h"

DLLNode::DLLNode()
{
	prev=next=0;
}

DLLNode::DLLNode(int el)
{
	info=el;
	prev=next=0;
}

DLLNode::~DLLNode()
{
}