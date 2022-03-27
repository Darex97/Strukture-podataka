template <class T>
class Deque
{
public:
	virtual T getHead() {
		throw "Virtual function call"; }

	virtual T getTail() {
	throw "Virtual function call"; }

	virtual void enqueueHead(T object){
		throw "Virtual function call"; }

	virtual void enqueueTail(T object){
		throw "Virtual function call"; }

	virtual T dequeueHead() {
		throw "Virtual function call"; }

	virtual T dequeueTail() {
		throw "Virtual function call"; }

	virtual bool isEmpty() {return true;}

	virtual long numberOfElements() {return 0;}
};

