#include "QueueAsArray.h"
class StackAsArray :public QueueAsArray
{
public:
	StackAsArray(int);
	void push(int);
	int pop();
	int gettop(){return niz[tail];};
	virtual bool IsEmpty(){return tail==-1;};
	virtual int vratibrelemenata(){return tail+1;};
	void stampaj();
};