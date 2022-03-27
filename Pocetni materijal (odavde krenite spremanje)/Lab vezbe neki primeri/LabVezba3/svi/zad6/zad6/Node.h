#include <iostream>
using namespace std;
class Node
{
	int info;
	Node* next;
	Node* prev;
public:
	Node();
	Node(int,Node*,Node*);
	int getinfo(){return info;};
	void setinfo(int x){info=x;};
	Node* getnext(){return next;};
	Node* getprev(){return prev;};
	void setnext(Node * sl){next=sl;};
	void setprev(Node * pr){prev=pr;};
	void print();
};