#pragma once
#include<iostream>
using namespace std;
template<class T>
class Niz
{protected:
	T* niz; //data
	int osnova; // odakle pocinje od kog broja    base
	int duzina; // duzina niza      lenght
public:
	Niz(int o, int d) {
		osnova = o;
		duzina = d;
		niz = new T[d];

	}
	Niz(int d)
	{
		duzina = d;
		niz = new T[d];
		osnova = 0;
	}
	~Niz() { delete[] niz; }
	
	Niz& operator=(Niz<T>& nizz);
	T& operator[](int index);
	
	
	T& getAt(int index);
	void setAt(T el, int index);
	void print();


	T* getData() { return niz; }
	int getBase() { return osnova; }
	int getLenght() { return  duzina; }
	inline void setBase(int n) { osnova = n; }
	void setLenght(int l) { duzina = l; }
	
};
template<class T>
 Niz<T>& Niz<T>::operator=(Niz<T>& nizz) //proveri dal radi
{
	if (&nizz != this)
	{
		if (duzina != nizz.getLenght())
		{
			 delete[] niz;
			duzina = nizz.getLenght();
			niz = new T[duzina];
		}
		for (int i = 0; i < duzina; i++)
			niz[i] = nizz.niz[i];
		osnova = nizz.getBase();
	}
	return *this;
}
template<class T>
T& Niz<T>::operator[](int index)
{
	int razmak = index - osnova;
	if (razmak >= duzina)
		throw exception("Sjeban index");
	return niz[razmak];
}
template<class T>
void Niz<T>::print()
{
	for (int i = 0; i < duzina; i++)
		cout << "niz[" << i << "]=" << niz[i] << endl;
}
template<class T>
T& Niz<T>::getAt(int index)
{
	int razmak = index - osnova;
	if (razmak >= duzina)
		throw exception("Sjeban index");
	return niz[razmak];

}
template<class T>
void Niz <T>::setAt(T el, int index)
{
	int pozicija = index - osnova;
	if(pozicija>=duzina)
		throw exception("Sjeban index2");
	niz[pozicija] = el;

}