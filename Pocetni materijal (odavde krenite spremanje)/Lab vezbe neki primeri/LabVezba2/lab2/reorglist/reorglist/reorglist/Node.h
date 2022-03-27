#pragma once

class Node
{
public:
	Node() : _data(0), _next(0) {}
	Node(int data) : _data(data), _next(0) {}
	Node(int data, Node* next): _data(data), _next(next) {}

	~Node() {}

	int getData() { return _data; }
	Node* getNext() { return _next; }

	void setData(int data) { _data = data; }
	void setNext(Node* next) { _next = next; }

private:
	int _data;
	Node* _next;
};