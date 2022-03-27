#include <iostream>
using namespace std;
template <class T>
class Red
{
private:
	int head, tail, kapacitet;
	T* niz;
public:
	Red(int x)
	{
		kapacitet = x;
		niz = new T[kapacitet];
		head = -1;
		tail = 0;
	}
	~Red()
	{
		delete[] niz;
	}
	void Push(T x)
	{
		if ((tail + 1) % kapacitet == head)
		{
			cout << "pun red!" << endl;
			return;
		}
		niz[tail] = x;
		if (head == -1)
			head = tail;
		tail = (tail + 1) % kapacitet;		
	}
	T Pop()
	{
		if (head == -1)
		{
			cout << "prazan magacin!!!" << endl;
			return NULL;
		}
		T pom = niz[head];
		head = (head + 1) % kapacitet;
		if (head == tail)
			head = -1;

		return pom;
	}
	bool isEmpty()
	{
		if (head == -1)
			return true;
		return false;
	}
};