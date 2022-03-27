#pragma once
template<class T>
class DLLNode {
public:
	T info;
	DLLNode<T> *prev, *next;//pokazivaci na susede

	DLLNode() {prev = NULL; next = NULL;}
	DLLNode(T el) { info = el; prev = NULL; next = NULL;  }
	DLLNode(T el, DLLNode<T>* p, DLLNode<T>* n) {
		info = el;
		prev = p;
		next = n;
	}
	~DLLNode() {};
	T print() { return info; }
	bool isEqual(T el) { return info == el; }

};