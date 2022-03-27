#include "Node.h"

Node::Node()
{
	next=NULL;
	prev=NULL;
}
Node::Node(int x,Node* pr,Node* sl)
{
	info=x;
	prev=pr;
	next=sl;
}
void Node::print()
{
	cout<<info<<" ";
}