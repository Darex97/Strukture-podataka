#include "Node.h"

Node::Node()
{
	next=NULL;
}
Node::Node(int x,Node* sl)
{
	info=x;
	next=sl;
}
void Node::print()
{
	cout<<info<<endl;
}