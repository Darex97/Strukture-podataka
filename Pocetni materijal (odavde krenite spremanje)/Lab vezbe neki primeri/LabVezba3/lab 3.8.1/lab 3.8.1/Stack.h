#include <iostream>

using namespace std;

template<class T>
class Stack
{

public:

	T *niz;
	int top;
	int size;

	Stack();

	Stack(int x)
	{
		size=x;
		niz = new T[size];
		top=-1;
	}

	~Stack()
	{
		delete [] niz;
	}

	bool isEmpty()
	{
		return top==-1;
	}

	void push(T x)
	{
		if(++top=size)
			throw  Exception("stack overflow");
		niz[top]=x;
	}

	T pop()
	{
		if(isEmpty())
			throw Exception("stack underflow");
		return niz[top--];
	}

	T getTop()
	{
		if(isEmpty())
			throw Exception("stack underflow");
		return niz[top];
	}

	void copyStack(Stack<T> &s)				//kopira jedan stek u drugi
	{
		if(size!=s.size)
			throw 
			Exception("Stacks have diferent sizes");
		Stack<T> pom(size);
		int pom_top=top;					//cuva top prvog steka jer cu koristiti getTop i smanjivati top rucno
		while(top>-1)						//sve dok se ne dodje do dna prvog steka
		{
			s.top=-1;						//postavlja top drugog steka na dno
			pom.push(getTop());				//prebacuje tekuci element prvog steka na pomocni
			top--;							//smanjuje top prvog steka
		}
		while(pom.top>-1)					//isti postupak prebacivanja iz pomocnog u drugi stek
			s.push(pom.pop());				//////////////////////////////////////////////////////
		top=pom_top;						//vraca top prvog steka na pocetnu vrednost, jer nismo skidali elemente vec ih samo kopirali
	}


};
