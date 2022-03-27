class Queue
{
	int *niz;
	int velicina;
	int tail;
	int head;
	int brel;
public:
	Queue(int);
	~Queue();
	void enqueue(int);
	int dequeue();
	bool IsEmpty(){return brel==0;};
	int gethead(){return niz[head];};
};