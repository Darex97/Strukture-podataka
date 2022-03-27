class QueueAsArray
{
protected:
	int *niz;
	int velicina;
	int head;
	int tail;
	int brel;
public:
	QueueAsArray(int);
	virtual ~QueueAsArray();
	int gethead(){return niz[head];};
	int gettail(){return niz[tail];};
	void enqueue(int);
	int dequeue();
	virtual bool IsEmpty(){return brel==0;};
	virtual int vratibrel(){return brel;};
};