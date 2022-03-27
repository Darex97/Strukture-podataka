template <class T>
class BinaryMinHeap
{
protected:
	T* array;
	long length;
	long numOfElements;
public:
	BinaryMinHeap (long len){
		length = len;
		numOfElements = 0;
		array = new T[length + 1];
	}
	~BinaryMinHeap (){ delete [] array;};
	bool isEmpty(){ return numOfElements == 0; };
	void insert(T el);
	T deleteRoot();
	static void HeapSort(T* a, long n);
};


template <class T>
void BinaryMinHeap<T>::insert (T el)
{
	if(numOfElements == length - 1)
		throw new SBPException("The heap is full!");
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
T BinaryMinHeap<T>::deleteRoot ()
{
	if(numOfElements == 0)
		throw new SBPException("The heap is empty!");
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
void BinaryMinHeap<T>::HeapSort(T* a, long n)
{
	BinaryMinHeap<T> heap(n+l);
	// Umetanje elemenata polja u heap
	for(long i=0; i<n; i++)
		heap.insert(a[i]);
	// Brisanje korena i smestanje u polje
	i = 0;
	while(!heap.isEmpty())
		a[i++]=heap.deleteRoot();
}		