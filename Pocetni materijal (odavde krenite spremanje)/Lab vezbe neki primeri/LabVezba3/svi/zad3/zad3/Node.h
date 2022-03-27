#include <iostream>
using namespace std;
class Node
{
	int info;
	Node* next;
public:
	Node();
	Node(int);
	Node(int,Node*);
	void setinfo(int x){info=x;};
	int getinfo(){return info;};
	void setnext(Node* sl){next=sl;};
	Node* getnext(){return next;};
	void print();
};