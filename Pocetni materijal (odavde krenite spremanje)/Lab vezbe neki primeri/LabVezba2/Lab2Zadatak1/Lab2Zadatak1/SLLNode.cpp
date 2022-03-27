#include "SLLNode.h"


SLLNode::SLLNode(void)
{
	this->next=NULL;
}
SLLNode::SLLNode(int e,double c)
{
	this->coef=c;
	this->exp=e;
	this->next=NULL;
}
ostream& operator<<(ostream& out,SLLNode& s)
{
	out<<s.coef<<"X^"<<s.exp<<" ";
	return out;
}
SLLNode::~SLLNode()
{
}
