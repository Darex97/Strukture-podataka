#pragma once
#include "KeySLNode.h"

template<class T,class R>
class KeySLList {
private:
	KeySLNode<T, R>* head;
public:
	KeySLList() { head = nullptr; }
	~KeySLList() { while (!isEmpty()) removeFromHead(); }
	bool isEmpty() {
		return head == nullptr;
	}
	void removeFromHead() {
		if (!head)
			throw exception("The list is empty");
		else
		{
			KeySLNode<T, R>* ptr = head;
			head = ptr->getNext();
			delete ptr;
		}
	}
	KeySLNode<T, R>* getHead() { return head; }
	void printList() {
		KeySLNode<T,R>* ptr = head;
		while (ptr != nullptr) {
			cout <<"("<<ptr->getKey()<<"," <<ptr->getValue()<<")" << "|" << ptr->getNext() << " -> ";;
			ptr = ptr->getNext();
		}
		cout << endl;
	}
	void insertOrUpdate(R key, T value) {
		if (isEmpty() || head->getKey()>key)
		{
			KeySLNode<T, R>* node = new KeySLNode<T, R>(value, key,head);
			head = node;
		}
		else {
			KeySLNode<T, R>* ptr = head;
			KeySLNode<T, R>* prev = nullptr;
			while (ptr != nullptr && ptr->getKey() < key) {
				prev = ptr;
				ptr = ptr->getNext();
			}

			if (ptr && ptr->getKey()==key) {
				ptr->getValueRef() = value;
				if (ptr->getValue() == (R)0)
				{
					if (ptr == head)
						head = head->getNext();
					else
						prev->getNextRef() = ptr->getNext();
					delete ptr;
					ptr = nullptr;
				}
			}
			else {
				KeySLNode<T, R>* node = new KeySLNode<T, R>(value, key, ptr);
				prev->getNextRef() = node;
			}
		}
	}



};