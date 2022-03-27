#include "Node.h"

Node::Node()
{
	next=0;
}
Node::Node(int x)
{
	info=x;
	next=NULL;
}
Node::Node(int x,Node* sl)
{
	info=x;
	next=sl;
}