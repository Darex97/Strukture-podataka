
class StackAsArray
{
protected:
	int * array;
	int size;
	int top;

public:
	StackAsArray(int duzina);
	~StackAsArray();
	int getTop();
	void push(int el);
	int pop();
	bool isEmpty();
	int numberOfElements();
	void print();
};