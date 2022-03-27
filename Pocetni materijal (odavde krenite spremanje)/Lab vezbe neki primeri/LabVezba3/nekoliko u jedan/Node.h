#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
	Node* next;
	int info;
  Node()
  {
	  next=NULL;
  }
  Node( int n)
  {
	  this->info=n;
	  this->next=NULL;
  }
  Node(int n,Node* k)
  {
	  info=n;
	  next=k;
  }
  ~Node()
  {
  }
};
