template <class T>
class BSTree
{
protected:
	T* array, *elem;
	long length, ukupnoC;
	long numOfElements;
public:
	BSTree (long len){
		length = len;
		numOfElements = 0;
		array = new T[length + 1];
		ukupnoC = 0;
		elem = new T[length];
	}
	~BSTree (){ delete [] array;};
	bool isEmpty(){ return numOfElements == 0; };
	void insert(T el);
	T deleteRoot();
	int nodeNum();
	void preOrder(int i);
};


template <class T>
void BSTree<T>::insert (T el)
{
	if(numOfElements == length - 1)
		throw "Stablo je popunjeno";
	numOfElements++;
	int i = numOfElements;
	while (i > 1 && array [i/2] > el)
	{
		array [i] = array [i / 2];
		i /= 2;
	}
	array [i] = el;
}

template <class T>
T BSTree<T>::deleteRoot ()
{
	if(numOfElements == 0)
		throw "Stablo je prazno";
	T result = array [1];
	T last = array [numOfElements];
	numOfElements—;
	long i = 1;
	while (2 * i < numOfElements + 1)
	{
		long child = 2 * i;
		if (child + 1 < numOfElements + 1 && array [child + 1] < array [child])
			child += 1;
		if (last <= array [child]) break;
		array [i] = array [child];
		i = child;
	}
	array [i] = last;
	return result;
}

template <class T>
int BSTree<T>::nodeNum()
{
	preOrder(0);
	return --ukupnoC;  // zato sto indexi krecu od 0
}

template <class T>
void BSTree<T>::preOrder(int i)
{
	if(i <= length)
	{
		bool postoji = false;				
		for(int x = 0; x < ukupnoC; x++)	
			if(ukupnoC > 0 && array[i] == elem[x])			
				postoji = true;
		if(! postoji)
			elem[ukupnoC++] = array[i];
		preOrder(2*i+1);
		preOrder(2*i+2);
	}
}
