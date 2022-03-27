#include "LinkedNode.h"
#include<iostream>
using namespace std;

LinkedNode::LinkedNode(int node,Edge* adjx,LinkedNode* nextx,int status)
{
	this->node=node;
	this->adj=adjx;
	this->next=nextx;
	this->status=status;
	this->indeg=this->outdeg=0;
}
LinkedNode::~LinkedNode(void)
{
}
