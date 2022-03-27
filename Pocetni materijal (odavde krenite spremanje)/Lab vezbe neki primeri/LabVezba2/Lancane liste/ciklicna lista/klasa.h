


class listel
{
protected:
	struct cvor
	{
		int info;
		struct cvor *link;
	};
	cvor *head, *tail ;
public:

	listel();
	bool IsEmpty();
	void AddToHead(int t);
	void AddToTail(int t);
	int tellfromHead();
	int tellfromTail();
	void print();
	void deleteFromHead();
	void deleteFromTail();
	~listel();

};
