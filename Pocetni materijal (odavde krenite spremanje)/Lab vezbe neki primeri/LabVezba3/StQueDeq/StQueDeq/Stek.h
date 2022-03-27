template <class T>
class Stek
{
public:
	virtual T getTop() {
		throw "Virtual function call!";};
	virtual void push(T object) {
		throw "Virtual function call!";};
	virtual T pop() {throw "Virtual function call!";};
	virtual bool isEmpty() {return true;}
	virtual long numberOfElements() {return 0;}
};