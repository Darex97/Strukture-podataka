#include "Tree.h"

Tree::Tree(int numberOfLevels)
{
	if ( numberOfLevels > 0 )
	{
		int numberOfElemets = 2;

		if ( numberOfLevels != 1)
			for ( int i = 1; i < numberOfLevels; i++ )
				numberOfElemets *= 2;

		_taken = new bool [numberOfElemets-1];
		_key = new int [numberOfElemets-1];
		_left = new int [numberOfElemets-1];
		_right = new int [numberOfElemets-1];

		_maxNumberOfElements = numberOfElemets-1;
		_currNumberOfElements = 0;
		_numberOfLevels = numberOfLevels;

		for ( int i = 0; i < numberOfElemets-1; i++ )
		{
			_taken[i] = false;
			_key[i] = -999999999;
			if ( i < ( ( numberOfElemets / 2 ) - 1 ) )
			{
				_left[i] = 2 * i + 1;
				_right[i] = 2 * i + 2;
			}
			else
			{
				_left[i] = -1;
				_right[i] = -1;
			}
		}
	}
	else
		throw new exception ("Binary tree must have at least one level");
}

Tree::~Tree()
{
	delete _taken;
	delete _key;
	delete _left;
	delete _right;
}

void Tree::insert(int element)
{
	if ( isFull() )
		throw new exception ("Tree already full, can't insert any more elements");
	else
	{
		int curr = 0;
		int prev = -1;

		int counter = 0;

		while ( counter <= _numberOfLevels && curr != -1 && _taken[curr] != false )
		{
			prev = curr;

			if ( _key[curr] < element )
				curr = _right[curr];
			else
				curr = _left[curr];

			counter++;
		}

		if ( counter > _numberOfLevels || curr == -1 )
			throw new exception ("Tree doesn't have enough levels to insert element");

		if ( _taken[0] == false )
		{
			_taken[0] = true;
			_key[0] = element;
		}
		else if ( _key[prev] < element )
		{
			_taken[_right[prev]] = true;
			_key[_right[prev]] = element;
		}
		else
		{
			_taken[_left[prev]] = true;
			_key[_left[prev]] = element;
		}

		_currNumberOfElements++;
	}
}

void Tree::remove(int element)
{
	int index = search(element);

	int* data = toOrganizedArray();
	int size = _currNumberOfElements;

	int arrayPos;
	bool found = false;

	for ( int i = 0; i < size && found != true; i++ )
		if ( data[i] == element )
		{
			arrayPos = i;
			found = true;
		}
		else
			;

	int swapEl = data[arrayPos-1];
	
	int swapIndex = search(swapEl);

	if ( swapIndex > index )
	{
		_key[index] = _key[swapIndex];
		if ( _taken[_left[swapIndex]] == true || _taken[_right[swapIndex]] == true )
			remove(swapEl);
		else
		{
			_taken[swapIndex] = false;
			_key[swapIndex] = -999999999;
			_currNumberOfElements--;
		}
	}
	else
	{
		swapEl = data[arrayPos+1];
	
		swapIndex = search(swapEl);

		if ( swapIndex > index )
		{
			_key[index] = _key[swapIndex];
			if ( _taken[_left[swapIndex]] == true || _taken[_right[swapIndex]] == true )
				remove(swapEl);
			else
			{
				_taken[swapIndex] = false;
				_key[swapIndex] = -999999999;
				_currNumberOfElements--;
			}
		}
	}
}

int Tree::search(int element)
{
	if ( isEmpty() )
		return -1;

	int curr = 0;

	int counter = 0;

	while ( counter <= _numberOfLevels && _taken[curr] != false )
	{
		if ( _key[curr] == element )
			return curr;
		else if ( _key[curr] > element )
			curr = _left[curr];
		else
			curr = _right[curr];

		counter++;
	}

	return -1;
}

void Tree::balance()
{
	int* data = toOrganizedArray();
	for ( int i = 0; i < _maxNumberOfElements; i++ )
	{
		_taken[i] = false;
		_key[i] = -999999999;
	}
	int count = _currNumberOfElements;
	_currNumberOfElements = 0;
	balance(data,count);
}

void Tree::balance(int* data, int size)
{
	balance(data,0,size-1);
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


void Tree::preorder(int coef)
{
	if ( coef != -1 && _taken[coef] == true )
	{
		cout << _key[coef] << " ";
		preorder(_left[coef]);
		preorder(_right[coef]);
	}
}

void Tree::inorder(int coef)
{
	if ( coef != -1 && _taken[coef] == true )
	{
		inorder(_left[coef]);
		cout << _key[coef] << " ";
		inorder(_right[coef]);
	}
}

void Tree::postorder(int coef)
{
	if ( coef != -1 && _taken[coef] == true )
	{
		postorder(_left[coef]);
		postorder(_right[coef]);
		cout << _key[coef] << " ";
	}
}

int* Tree::toArray()
{
	int size = 0;

	for ( int i = 0; i < _maxNumberOfElements; i++ )
		if ( _taken[i] == true )
			size++;

	int* ret = new int [size];

	int counter = 0;

	for ( int i = 0; i < _maxNumberOfElements && counter < size; i++ )
		if ( _taken[i] == true )
			ret[counter++] = _key[i];

	return ret;
}

int* Tree::toOrganizedArray()
{
	int* ret = toArray();

	int size = 0;

	for ( int i = 0; i < _maxNumberOfElements; i++ )
		if ( _taken[i] == true )
			size++;

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

void Tree::print()
{
	cout << "Static binary tree:" << endl;
	cout << endl;

	for ( int i = 0; i < _maxNumberOfElements; i++ )
	{
		if ( i < 10 )
			cout << i << ".  ";
		else
			cout << i << ". ";

		if ( _taken[i] == true )
			cout << "taken ";
		else
			cout << "free  ";

		cout << _key[i] << " ";
		cout << _left[i] << " ";
		cout << _right[i] << " ";

		cout << endl;
	}

	cout << endl;
}



int Tree::differentNodes()
{
	int* data = toArray();
	int end = _currNumberOfElements;

	for ( int i = 0; i < end; i++ )
		for ( int j = i+1; j < end; j++ )
		{
			if ( data[i] == data[j] )
			{
				for ( int k = j; k < end - 1; k++ )
					data[k] = data[k+1];
				end--;
			}
		}	
		return end;
}

int Tree::height()
{
	if ( !isEmpty() )
	{
		bool found = false;
		int index = 0;
		int ret = 1;

		int i;

		for ( i = _maxNumberOfElements - 1; i > 0 && found != true; i-- )
			if ( _taken[i] == true )
			{
				index = i;
				found = true;
			}

		found = false;

		int temp = 0;
		int add = 2;

		for ( i = 1; i <= _numberOfLevels && found != true; i++ )
		{
			temp += add;
			add *= 2;
			if ( temp <= index )
				ret++;
			else
				found = true;
		}

		return ret;
	}
	else
		return 0;
}

int Tree::moment()
{
	return _currNumberOfElements;
}

int Tree::numberOfLeaves()
{
	int ret = 0;

	for ( int i = 0; i < _maxNumberOfElements; i++ )
	{
		if ( i < ( _maxNumberOfElements / 2 ) )
			if ( _taken[i] == true && _taken[_left[i]] == false && _taken[_right[i]] == false )
					ret++;
			else
				;
		else
			if ( _taken[i] == true )
				ret++;
			else
				;
	}

	return ret;
}

void Tree::deleteLeaves()
{
	for ( int i = 0; i < _maxNumberOfElements; i++ )
	{
		if ( i < ( _maxNumberOfElements / 2 ) )
			if ( _taken[i] == true && _taken[_left[i]] == false && _taken[_right[i]] == false )
			{
				_taken[i] = false;
				_key[i] = -999999999;
			}
			else
				;
		else
			if ( _taken[i] == true )
			{
				_taken[i] = false;
				_key[i] = -999999999;
			}
			else
				;
	}
}

void Tree::mirror()
{
	for ( int i = 0; i < ( _maxNumberOfElements/2 ); i++ )
	{
		int temp = _left[i];
		_left[i] = _right[i];
		_right[i] = temp;
	}
}
//{
//	int* data = toOrganizedArray();
//
//	for ( int i = 0; i < _currNumberOfElements/2; i++ )
//	{
//		int temp = data[i];
//		data[i] = data[_currNumberOfElements-i-1];
//		data[_currNumberOfElements-i-1] = temp;
//	}
//
//	balance();
//}

void Tree::mix(Tree& t1, Tree& t2)
{
	int size1 = t1._currNumberOfElements;
	int size2 = t2._currNumberOfElements;

	int* data1 = t1.toArray();
	int* data2 = t2.toArray();

	int size = size1 + size2;
	int* data = new int [size];

	for ( int i = 0; i < size1; i++ )
		data[i] = data1[i];
	for ( int i = size1; i < size1 + size2; i++ )
		data[i] = data2[i - size1];

	for ( int i = 0; i < size-1; i++ )
		for ( int j = i+1; j < size; j++)
			if ( data[i] > data[j] )
			{
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}

	balance(data,size);
}

int Tree::levelWithMostNodes()
{
	if ( !isEmpty() )
	{
		int currLvl = 0;
		int currNodes = 0;
		int retLvl = 0;
		int maxNodes = 1;

		int temp = 0;
		int prev = -1;

		int add = 2;

		for ( int i = 1; i < _numberOfLevels; i++ )
		{
			prev = temp;
			temp += add;
			add *= 2;

			currNodes = 0;
			currLvl++;

			for ( int j = prev + 1; j <= temp; j++ )
				if ( _taken[j] == true )
					currNodes++;
				else
					;

			if ( currNodes > maxNodes )
			{
				retLvl = currLvl;
				maxNodes = currNodes;
			}
		}

		return retLvl;
	}
	else
		return -1;
}