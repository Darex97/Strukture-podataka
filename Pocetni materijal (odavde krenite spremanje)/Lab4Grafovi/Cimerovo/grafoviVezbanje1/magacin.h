#include <iostream>
using namespace std;
template <class T>
class Magacin
{
private:
	int kapacitet;
	int top;
	T* niz;
public:
	Magacin(int x)
	{
		top = -1;
		kapacitet = x;
		niz = new T[x];
	}
	~Magacin()
	{
		delete[] niz;
	}
	void Push(T n)
	{
		if (top == kapacitet - 1)
		{
			cout << "magacin je pun!!!" << endl;
			return;
		}
		niz[++top] = n;
	}
	T Pop()
	{
		if (!isEmpty())
		{
			return niz[top--];
		}
	}
	bool isEmpty()
	{
		if (top == -1)
			return true;
		return false;
	}
	T returnTop()
	{
		if (!isEmpty())
			return niz[top];
	}
};