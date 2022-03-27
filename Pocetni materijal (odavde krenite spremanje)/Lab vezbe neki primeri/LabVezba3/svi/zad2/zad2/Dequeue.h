class Dequeue
{

	int duzina;
	int head;
	int brelemenata;
protected:
	int *niz;
	int tail;
public:
	Dequeue(int);
	virtual ~Dequeue();
	int gethead(){return niz[head];};
	int gettail(){return niz[tail];};
	void enqueuehead(int);
	void enqueuetail(int);
	int dequeuehead();
	int dequeuetail();
	virtual bool IsEmpty(){return brelemenata==0;};
	virtual int vratibrelemenata(){return brelemenata;};
};