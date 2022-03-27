#include "Dequeue.h"
#include <iostream>
using namespace std;
class StackAsArray :public Dequeue
{
public:
		StackAsArray(int);
virtual ~StackAsArray();
virtual bool IsEmpty(){return tail==-1;};
virtual int vratibrelemenata(){return tail+1;};
		int gettop(){return gettail();};
		void push(int x){enqueuetail(x);};
		int pop(){return dequeuetail();};
		void stampaj();
};