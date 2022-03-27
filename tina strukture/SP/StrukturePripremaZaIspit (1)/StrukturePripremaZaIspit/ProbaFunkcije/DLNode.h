#pragma once
#include "SLNode.h"

class DLNode {
private:
	int value;
	DLNode* previous;
	DLNode* next;

public:
	DLNode() { value = 0; previous = next = nullptr; }
	DLNode(int value) {
		this->value = value;
		previous = next = nullptr;
	}
	DLNode(int value, DLNode* previous, DLNode* next) {
		this->value = value;
		this->previous = previous;
		this->next = next;
	}
	int getValue() {
		return value;	
	}
	DLNode* getPrevious() { return previous; }
	DLNode*& getPreviousRef() { return previous; }
	DLNode* getNext() { return next; }
	DLNode*& getNextRef() { return next; }
};