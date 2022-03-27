#include "SLLNode.h"
#include <iostream.h>

SLLNode::SLLNode()
{
	info=0;
	link=NULL;
}

SLLNode::SLLNode(int n)
{
	info=n;
	link=NULL;
}

SLLNode::~SLLNode()
{
}

void SLLNode::Print()
{
	cout<<"|"<<info<<"|";
}