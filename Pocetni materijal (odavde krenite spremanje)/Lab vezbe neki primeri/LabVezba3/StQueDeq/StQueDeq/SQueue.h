template <class T>
class SQueue
{
public:
	virtual T getHead() {
		throw "Virtual function call!";};

	virtual void enqueue(T object){
		throw "Virtual function call!";};

	virtual T dequeue() {
		throw "Virtual function call!";};

	virtual bool isEmpty() {
		throw "Virtual function call!";};

	virtual long numberOfElements(){
		throw "Virtual function call!";};
};