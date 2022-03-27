#pragma once

#include <stack>

#include "Node.h"

class Tree
{
public:
	Tree();
	~Tree();

	bool isEmpty();
	bool isInTree(int element);

	void deleteTree(Node* node);

	void insert(int element);

	Node* search(Node* node, int element);
	Node* search(int element) { return search(_root,element); }

	void inorder(Node* node);
	void inorder() { return inorder(_root); }

	void preorder(Node* node);
	void preorder() { preorder(_root); }

	void postorder(Node* node);
	void postorder() { postorder(_root); }

	//void deleteByCopying(int element);			NE RADI, MRZI ME DA GA PREPISJUJEM OPET IZ PRAKTIKUMA
	void deleteByMerging(int element);

	void balance();
	void balance(int* data, int size) { balance(data,0,size-1); }
	void balance(int* data, int first, int last);

	int getNumberOfElements() { return _numberOfElements; }

	int* toArray()
	{
		if ( getNumberOfElements() == 0 )
			return 0;

		int* data = new int [getNumberOfElements()];
		int i = 0;

		Node* curr = _root;
		stack<int> _stack;
		stack<Node*> stack_;

		if ( curr != 0 )
		{
			_stack.push(curr->getKey());
			stack_.push(curr);
			while ( !stack_.empty() )
			{
				curr = stack_.top();
				stack_.pop();

				data[i++] = _stack.top();
				_stack.pop();

				if ( curr->getLeft() != 0 )
				{
					_stack.push(curr->getLeft()->getKey());
					stack_.push(curr->getLeft());
				}
				if ( curr->getRight() != 0 )
				{
					_stack.push(curr->getRight()->getKey());
					stack_.push(curr->getRight());
				}
			}
		}
		return data;
	}

	int* toOrganizedArray()
	{
		int* ret = toArray();

		int size = _numberOfElements;

		for ( int i = 0; i < size-1; i++ )
			for ( int j = i+1; j < size; j++)
				if ( ret[i] > ret[j] )
				{
					int temp = ret[i];
					ret[i] = ret[j];
					ret[j] = temp;
				}

		return ret;
	}

	Node** toNodeArray()
	{
		if ( getNumberOfElements() == 0 )
			return 0;

		Node* *data = new Node* [getNumberOfElements()];
		int i = 0;

		Node* curr = _root;
		stack<Node*> _stack;

		{
			_stack.push(curr);
			while ( !_stack.empty() )
			{
				curr = _stack.top();
				data[i++] = _stack.top();
				_stack.pop();

				if ( curr->getLeft() != 0 )
				{
					_stack.push(curr->getLeft());
				}
				if ( curr->getRight() != 0 )
				{
					_stack.push(curr->getRight());
				}
			}
		}
		return data;
	}

	Node** toOrganizedNodeArray()
	{
	Node* *data = toNodeArray();

	int size = _numberOfElements;

	for ( int i = 0; i < size-1; i++ )
		for ( int j = i+1; j < size; j++)
			if ( data[i]->isGreater(data[j]->getKey()) )
			{
				int temp = data[i]->getKey();
				data[i]->setKey(data[j]->getKey());
				data[j]->setKey(temp);
			}

	return data;
	}
	//Funkcije sa vezbi

	int differentNodes();
	int height();
	int moment();
	int numberOfLeaves();
	void deleteLeaves();
	void mirror();
	void mix(Tree& t1, Tree& t2);
	int levelWithMostNodes();

private:
	Node* _root;
	int _numberOfElements;
};