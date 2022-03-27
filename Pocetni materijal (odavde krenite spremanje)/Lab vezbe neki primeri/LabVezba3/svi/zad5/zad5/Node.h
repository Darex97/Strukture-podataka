#include <iostream>
using namespace std;
class Node
{
	int info;
	Node* next;
public:
	Node();
	Node(int,Node*);
	int getinfo(){return info;};
	void setinfo(int x){info=x;};
	Node* getnext(){return next;};
	void setnext(Node * sl){next=sl;};
	void print();
};