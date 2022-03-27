#include "QueueAsArray.h"
#include <iostream>
using namespace std;
class DequeueAsArray : public QueueAsArray
{	
public:
	DequeueAsArray(int);
	void enqueuehead(int);
	int dequeuetail();
	void stampaj();
};