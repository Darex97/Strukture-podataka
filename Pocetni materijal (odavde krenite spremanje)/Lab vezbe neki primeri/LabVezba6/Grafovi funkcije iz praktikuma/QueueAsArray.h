template <class T>
class QueueAsArray
{
protected:
	T* array;				// polje elemenata
	long size;				// velicina polja
	long head;				// indeks pocetnog elementa
	long tail;				// indeks krajnjeg elementa
	long numOfElements;		// broj elemenata u redu

public:
	QueueAsArray(long nsize)
	{
		size = nsize;
		array = new T[size];
		head = tail = -1;
		numOfElements = 0;
	}

	bool isEmpty() { return (numOfElements == 0); }
	long numberOfElements() { return numOfElements; }
	~QueueAsArray() { delete [] array; }

	T getHead()
	{
		if(numOfElements == 0)
			throw new SBPException("Queue underflow!");
		return array[head];
	}

	void enqueue(T object)
	{
		if(numOfElements == size)
			throw new SBPException("Queue overflow!");
		if(++tail == size) tail = 0;
		array[tail] = object;
		if(numOfElements == 0) head = tail;
		numOfElements++;
	}

	T dequeue()
	{
		if(numOfElements == 0)
			throw new SBPException("Queue underflow!");
		T result = array[head];
		if(++head == size) head = 0;
		numOfElements--;
		if(numOfElements == 0) head = tail = -1;
		return result;
	}
};