#pragma once

template <class T>
class SLLNode
{
public:
	T info;
	SLLNode<T>* next;

public:
	SLLNode() { this->next = nullptr; }
	SLLNode(T info) { this->info = info; this->next = nullptr; }
	SLLNode(T info, SLLNode<T>* node) { this->info = info; this->next = node; }

	~SLLNode() { }

	T print() const { return this->info; }
	bool isEqual(T element) const { return this->info == element; }
};