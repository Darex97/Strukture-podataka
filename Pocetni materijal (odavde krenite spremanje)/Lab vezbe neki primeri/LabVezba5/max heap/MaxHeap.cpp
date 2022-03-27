#include "MaxHeap.h"



MaxHeap::MaxHeap() : _root(0), _numberOfElements(0) {}



MaxHeap::~MaxHeap()
{
	_delete(_root);
	//delete _root;
}



void MaxHeap::insert(int element)			//Preradjena verzija inserta u stablo, ne koristi se u programu
{
	Node* curr = _root;
	Node* prev = 0;

	stack<Node*> _stack;

	while ( curr != 0 )
	{
		prev = curr;

		if ( prev->isLesser(element))
			curr = curr->getRight();
		else
			curr = curr->getLeft();

		_stack.push(prev);
	}

	if ( _root == 0 )
		_root = new Node(element);
	else if ( prev->isLesser(element))
	{
		prev->setRight(new Node(element));
		curr = prev->getRight();
	}
	else
	{
		prev->setLeft(new Node(element));
		curr = prev->getLeft();
	}

	bool found = false;

		while ( !_stack.empty() && found != true )
	{
		prev = _stack.top();

		if ( prev->isLesser(curr->getKey()))
		{
			int temp = curr->getKey();
			curr->setKey(prev->getKey());
			prev->setKey(temp);

			_stack.pop();
		}
		else
			found = true;

		curr = prev;
	}

		_numberOfElements++;
}



void MaxHeap::heapInsert(int element)
{
	Node* previous = 0;
	Node* curr = _root;
	Node* heapCurr = 0;		//koristi se u nalazenju mesta novoubacenog noda
	Node* help = 0;			//node uz pomoc kog se trazi _help
	Node* _help = 0;		//node na koji se treba nadovezati novi node

	stack<Node*> _stack;
	stack<Node*> stack_;

	bool levelNotFull = false;
	int find = 0;					// neke promenjive koje se koriste za nalazenje mesta za umetnaje novog elementa

	int counter = 0;

	_stack.push(curr);

	while ( curr != 0 )
	{
		while ( !_stack.empty() )
		{
			stack_.push(_stack.top());
			_stack.pop();
		}

		while ( !stack_.empty() )
		{
			help = stack_.top();
			
			if ( find == 0 )
				if ( help->getLeft() == 0 || help->getRight() == 0 )
				{
					levelNotFull = true;
					_help = help;

					find++;
				}

			_stack.push(stack_.top());
			stack_.pop();
		}

		while ( !_stack.empty() )
		{
			stack_.push(_stack.top());
			_stack.pop();
		}

		while ( !stack_.empty() )
		{
			curr = stack_.top();
		
			stack_.pop();

			if ( curr != 0 )
			{

				_stack.push(curr->getLeft());
				_stack.push(curr->getRight());

				counter++;
			}
		}
	}

	while ( !_stack.empty() )
			_stack.pop();

	while ( !stack_.empty() )
		stack_.pop();

	if ( curr == 0 && _numberOfElements == 0 )
		_root = new Node(element);
	else
		curr = new Node(element);

	previous = _help;

	if ( _numberOfElements > 0 && counter % 2 != 0 )
		previous->setRight(curr);
	else if ( _numberOfElements > 0 && counter % 2 == 0 )
		previous->setLeft(curr);
	else
		;

	bool found = false;

	counter++;					//postavlja counter na mesto na kom se nalazi element

	if ( _numberOfElements == 0 )
		found = true;

	while ( found != true )
	{
		int prev = counter / 2;

		if ( prev == 0 || prev == counter )
			found = true;

		int temp = 0;

		_stack.push(_root);

		while ( temp < prev )
		{
			while ( !_stack.empty() )
			{
				stack_.push(_stack.top());
				_stack.pop();
			}

			while ( !stack_.empty() && temp < prev )
			{
				heapCurr = stack_.top();
				stack_.pop();

				if ( temp < prev )
					previous = heapCurr;

				if ( heapCurr != 0 )
				{
					_stack.push(heapCurr->getLeft());
					_stack.push(heapCurr->getRight());

					temp++;
				}
			}
		}

		if ( previous->getKey() < curr->getKey() )
		{
			int swap = curr->getKey();
			curr->setKey(previous->getKey());
			previous->setKey(swap);

			counter = prev;

			curr = previous;

			while ( !_stack.empty() )
				_stack.pop();

			while ( !stack_.empty() )
				stack_.pop();
		}
		else
			found = true;
	}

	_numberOfElements++;
}



void MaxHeap::mix(MaxHeap& mh1, MaxHeap& mh2)
{
	int* data1 = mh1.toArray();
	int size1 = mh1._numberOfElements;

	int* data2 = mh2.toArray();
	int size2 = mh2._numberOfElements;

	int size = size1 + size2;
	int* data = new int [size];

	for ( int i = 0; i < size1; i++ )
		data[i] = data1[i];
	for ( int i = size1; i < size1 + size2; i++ )
		data[i] = data2[i - size1];

	if ( !isEmpty() )
		_delete(_root);

	for ( int i = 0; i < size; i++ )
		heapInsert(data[i]);
}



void MaxHeap::toMinHeap()
{
	int* _data = toOrganizedArray();

	//Node* *data_ = toOrganizedNodeArray();

	int size = _numberOfElements;

	reset();

	for ( int i = 0; i < size; i++ )
	{
		/*data_[i]->setKey(_data[size-1-i]);
		invertInsert(data_[i]->getKey());*/

		heapInvertInsert(_data[i]);
	}
}

//PRIVATE FUNCTIONS

void MaxHeap::invertInsert(int element)			//isto kao i insert(int element) ne koristi se, ali nisam hteo da ga brisem kad sam ga vec napisao
{
		Node* curr = _root;
		Node* prev = 0;

		stack<Node*> _stack;

		while ( curr != 0 )
		{
			prev = curr;

			if ( prev->isLesser(element))
				curr = curr->getLeft();
			else
				curr = curr->getRight();

			_stack.push(prev);
		}

		if ( _root == 0 )
			_root = new Node(element);
		else if ( prev->isLesser(element))
		{
			prev->setLeft(new Node(element));
			curr = prev->getLeft();
		}
		else
		{
			prev->setRight(new Node(element));
			curr = prev->getRight();
		}

		bool found = false;

		while ( !_stack.empty() && found != true )
		{
			prev = _stack.top();

			if ( prev->isGreater(curr->getKey()))
			{
				int temp = curr->getKey();
				curr->setKey(prev->getKey());
				prev->setKey(temp);

				_stack.pop();
			}
			else
				found = true;

			curr = prev;
		}

			_numberOfElements++;
}



void MaxHeap::heapInvertInsert(int element)
{
	Node* previous = 0;
	Node* curr = _root;
	Node* heapCurr = 0;		//koristi se u nalazenju mesta novoubacenog noda
	Node* help = 0;			//node uz pomoc kog se trazi _help
	Node* _help = 0;		//node na koji se treba nadovezati novi node

	stack<Node*> _stack;
	stack<Node*> stack_;

	bool levelNotFull = false;
	int find = 0;					// neke promenjive koje se koriste za nalazenje mesta za umetnaje novog elementa

	int counter = 0;

	_stack.push(curr);

	while ( curr != 0 )
	{
		while ( !_stack.empty() )
		{
			stack_.push(_stack.top());
			_stack.pop();
		}

		while ( !stack_.empty() )
		{
			help = stack_.top();
			
			if ( find == 0 )
				if ( help->getLeft() == 0 || help->getRight() == 0 )
				{
					levelNotFull = true;
					_help = help;

					find++;
				}

			_stack.push(stack_.top());
			stack_.pop();
		}

		while ( !_stack.empty() )
		{
			stack_.push(_stack.top());
			_stack.pop();
		}

		while ( !stack_.empty() )
		{
			curr = stack_.top();
		
			stack_.pop();

			if ( curr != 0 )
			{

				_stack.push(curr->getLeft());
				_stack.push(curr->getRight());

				counter++;
			}
		}
	}

	while ( !_stack.empty() )
			_stack.pop();

	while ( !stack_.empty() )
		stack_.pop();

	if ( curr == 0 && _numberOfElements == 0 )
		_root = new Node(element);
	else
		curr = new Node(element);

	previous = _help;

	if ( _numberOfElements > 0 && counter % 2 != 0 )
		previous->setRight(curr);
	else if ( _numberOfElements > 0 && counter % 2 == 0 )
		previous->setLeft(curr);
	else
		;

	bool found = false;

	counter++;					//postavlja counter na mesto na kom se nalazi element

	if ( _numberOfElements == 0 )
		found = true;

	while ( found != true )
	{
		int prev = counter / 2;

		if ( prev == 0 || prev == counter )
			found = true;

		int temp = 0;

		_stack.push(_root);

		while ( temp < prev )
		{
			while ( !_stack.empty() )
			{
				stack_.push(_stack.top());
				_stack.pop();
			}

			while ( !stack_.empty() && temp < prev )
			{
				heapCurr = stack_.top();
				stack_.pop();

				if ( temp < prev )
					previous = heapCurr;

				if ( heapCurr != 0 )
				{
					_stack.push(heapCurr->getLeft());
					_stack.push(heapCurr->getRight());

					temp++;
				}
			}
		}

		if ( previous->getKey() > curr->getKey() )
		{
			int swap = curr->getKey();
			curr->setKey(previous->getKey());
			previous->setKey(swap);

			counter = prev;

			curr = previous;

			while ( !_stack.empty() )
				_stack.pop();

			while ( !stack_.empty() )
				stack_.pop();
		}
		else
			found = true;
	}

	_numberOfElements++;
}



void MaxHeap::_delete(Node* node)
{
	if ( node != 0 )
	{
		_delete(node->getLeft());
		_delete(node->getRight());
		delete node;

		_numberOfElements--;
		
		/*if ( node == _root )
			_root = 0;*/
	}
}



int* MaxHeap::toArray()
{
	if ( _numberOfElements == 0 )
		return 0;

	int* data = new int [_numberOfElements];
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



int* MaxHeap::toOrganizedArray()
{
	int* data = toArray();

	int size = _numberOfElements;

	for ( int i = 0; i < size-1; i++ )
		for ( int j = i+1; j < size; j++)
			if ( data[i] > data[j] )
			{
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}

	return data;
}


Node** MaxHeap::toNodeArray()
{
	if ( _numberOfElements == 0 )
		return 0;

	Node* *data = new Node* [_numberOfElements];
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
				_stack.push(curr->getLeft());

			if ( curr->getRight() != 0 )
				_stack.push(curr->getRight());
		}
	}

	return data;
}



Node** MaxHeap::toOrganizedNodeArray()
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