class QueueAsArray
{
	int duzina;
	int head;
	int brelemenata;
protected:
	int *niz;
	int tail;
public:
	QueueAsArray(int);
	virtual ~QueueAsArray();
	int gethead(){return head;};
	void enqueue(int);
	int dequeue();
	virtual bool IsEmpty(){return brelemenata==0;};
	virtual int vratibrelemenata(){return brelemenata;};
};