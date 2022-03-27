#include "Tree.h"

Tree::Tree() : _root(0), _numberOfElements(0) {}

Tree::~Tree() { deleteTree(_root); delete _root; }

bool Tree::isEmpty() { return _root == 0; }

bool Tree::isInTree(int element) { return search(element) == 0; }

void Tree::deleteTree(Node* node)
	{
		if ( node != 0 )
		{
			deleteTree(node->getLeft());
			deleteTree(node->getRight());
			delete node;
			_numberOfElements--;
			if ( node == _root )
				_root = 0;
		}
	}

void Tree::insert(int element)
	{
		Node* curr = _root;
		Node* prev = 0;

		while ( curr != 0 )
		{
			prev = curr;
			if ( prev->isLesser(element))
				curr = curr->getRight();
			else
				curr = curr->getLeft();
		}

		if ( _root == 0 )
			_root = new Node(element);
		else if ( prev->isLesser(element))
			prev->setRight(new Node(element));
		else
			prev->setLeft(new Node(element));

		_numberOfElements++;
	}

Node* Tree::search(Node* node, int element)
	{
		while ( node != 0 )
		{
			if ( node->isEqual(element) )
				return node;
			else if ( node->isLesser(element) )
				node = node->getLeft();
			else
				node = node->getRight();
		}

		return 0;
	}

void Tree::inorder(Node* node)
	{
		if ( node != 0 )
		{
			inorder(node->getLeft());
			node->print();
			inorder(node->getRight());
		}
	}

void Tree::preorder(Node* node)
	{
		if ( node != 0 )
		{
			node->print();
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}

void Tree::postorder(Node* node)
	{
		if ( node != 0 )
		{
			postorder(node->getLeft());
			postorder(node->getRight());
			node->print();
		}
	}

void Tree::balance()
	{
		int* data = toOrganizedArray();
		int count = _numberOfElements;

		deleteTree(_root);

		balance(data,count);
	}

void Tree::balance(int* data, int first, int last)
	{
		if ( first <= last )
		{
			int middle = ( first + last ) / 2;
			insert(data[middle]);
			balance(data,first,middle-1);
			balance(data,middle+1,last);
		}
	}

void Tree::deleteByMerging(int element)
	{
		Node* temp;
		Node* node;
		Node* curr = _root;
		Node* prev = 0;

		while ( curr != 0 && !curr->isEqual(element) )
		{
			prev = curr;
			if ( curr->isLesser(element) )
				curr = curr->getRight();
			else
				curr = curr->getLeft();
		}

		node = curr;

		if ( curr != 0 && curr->isEqual(element) )
		{
			if ( node->getRight() == 0 )
				node = node->getLeft();
			else if ( node->getLeft() == 0 )
				node = node->getRight();
			else
			{
				temp = node->getLeft();
				while ( temp->getRight() != 0 )
					temp = temp->getRight();
				temp->setRight(node->getRight());
				node = node->getLeft();
			}
		}

		if ( curr == _root )
			_root = node;
		else if ( prev->getLeft() == curr )
			prev->setLeft(node);
		else
			prev->setRight(node);

		delete curr;

		_numberOfElements--;
	}

//		KO STO VEC REKOH, MRZI ME DA GA PISEM PA

//void Tree::deleteByCopying(int element)
//	{
//		Node* node;
//		Node* curr = _root;
//		Node* prev = 0;
//
//		while ( curr != 0 && !curr->isEqual(element) )
//		{
//			prev = curr;
//			if ( curr->isLesser(element) )
//				curr = curr->getRight();
//			else
//				curr = curr->getLeft();
//		}
//
//		node = curr;
//
//		if ( curr != 0 && curr->isEqual(element) )
//		{
//			if ( node->getRight() == 0 )
//				node = node->getLeft();
//			else if ( node->getLeft() == 0 )
//				node = node->getRight();
//			else
//			{
//				Node* temp = node->getLeft();
//				Node* previous = node;
//				while ( temp->getRight() != 0 )
//				{
//					previous = temp;
//					temp = temp->getRight();
//				}
//
//			node->setKey(temp->getKey());
//
//			if ( previous == node )
//				previous->setLeft(temp->getLeft());
//			else
//				previous->setRight(temp->getLeft());
//
//			delete temp;
//
//			_numberOfElements--;
//			}
//
//			if ( curr == _root )
//				_root = node;
//			else if ( prev->getLeft() == curr )
//				prev->setLeft(node);
//			else
//				prev->setRight(node);
//
//			delete curr;
//
//			_numberOfElements--;
//		}
//	}

		//Funkcije sa vezbi

int Tree::differentNodes()
{
	int* _data = toArray();
	int end = _numberOfElements;
	for ( int i = 0; i < end; i++ )
		for ( int j = i+1; j < end; j++ )
		{
			if ( _data[i] == _data[j] )
			{
				for ( int k = j; k < end - 1; k++ )
					_data[k] = _data[k+1];
				end--;
			}
		}	
		return end;
}

int Tree::height()
{
	if ( getNumberOfElements() == 0 )
		return 0;

	Node* curr = _root;
	stack<Node*> _stack;
	stack<Node*> _stack_;

	
	int ret = 0;

	{
		_stack.push(curr);

		while ( !_stack.empty() )
		{

			while ( !_stack.empty() )
			{
				_stack_.push(_stack.top());
				_stack.pop();
			}

			ret++;

			while ( !_stack_.empty() )
			{
				curr = _stack_.top();
				_stack_.pop();

				if ( curr->getLeft() != 0 )
					_stack.push(curr->getLeft());

				if ( curr->getRight() != 0 )
					_stack.push(curr->getRight());
			}
		}
		return ret;
	}
}

int Tree::moment() { return getNumberOfElements(); }

int Tree::numberOfLeaves()
{
	Node* *_nodes = toNodeArray();
	int size = getNumberOfElements();
	int ret = 0;

	for ( int i = 0; i < size; i++)
		if ( _nodes[i]->getLeft() == _nodes[i]->getRight() )
			ret++;

	return ret;
}

void Tree::deleteLeaves()
{
	Node* *_nodes = toNodeArray();
	int size = getNumberOfElements();
	bool done = false;

	for ( int i = 0; i < size; i++)
		if ( _nodes[i]->getLeft() == _nodes[i]->getRight() )
		{
			for ( int j = 0; j < size && done != true; j++ )
			{
				if ( _nodes[j]->getLeft() == _nodes[i] )
				{
					_nodes[j]->setLeft(0);
					done = true;
					_numberOfElements--;
				}
				else if ( _nodes[j]->getRight() == _nodes[i] )
				{
					_nodes[j]->setRight(0);
					done = true;
					_numberOfElements--;
				}
			}

			done = false;
			
			//delete _nodes[i];
		}
}

void Tree::mirror()
{
	Node* *data = toNodeArray();
	int size = getNumberOfElements();

	for ( int i = 0; i < size; i++ )
	{
		Node* temp = data[i]->getLeft();
		data[i]->setLeft(data[i]->getRight());
		data[i]->setRight(temp);
	}
}

void Tree::mix(Tree& t1, Tree& t2)
{
	int size1 = t1.getNumberOfElements();
	int size2 = t2.getNumberOfElements();

	int* data1 = t1.toArray();
	int* data2 = t2.toArray();

	int size = size1 + size2;
	int* data = new int [size];

	for ( int i = 0; i < size1; i++ )
		data[i] = data1[i];
	for ( int i = size1; i < size1 + size2; i++ )
		data[i] = data2[i - size1];

	deleteTree(_root);

	for ( int i = 0; i < size1 + size2; i++)
		insert(data[i]);
}

int Tree::levelWithMostNodes()
{
	if ( getNumberOfElements() == 0 )
		return 0;

	Node* curr = _root;
	stack<Node*> _stack;
	stack<Node*> _stack_;
	
	int LvlWithMostNodes = -1;
	int maxLvlNodes = 0;
	int currLvl = -1;
	int currLvlNodes = 0;

	{
		_stack.push(curr);

		while ( !_stack.empty() )
		{

			currLvl++;
			currLvlNodes = 0;

			while ( !_stack.empty() )
			{
				_stack_.push(_stack.top());
				_stack.pop();
				currLvlNodes++;
			}

			if ( currLvlNodes >= maxLvlNodes )
			{
				LvlWithMostNodes = currLvl;
				maxLvlNodes = currLvl;
			}

			while ( !_stack_.empty() )
			{
				curr = _stack_.top();
				_stack_.pop();

				if ( curr->getLeft() != 0 )
					_stack.push(curr->getLeft());

				if ( curr->getRight() != 0 )
					_stack.push(curr->getRight());
			}
		}
		return LvlWithMostNodes;
	}
}