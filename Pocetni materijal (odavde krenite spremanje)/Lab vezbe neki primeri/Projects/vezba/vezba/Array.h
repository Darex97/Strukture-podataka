#pragma once 
#include <iostream>
using namespace std;

class Array
{
protected:
	int osnova;
	int duzina;
	int* polje;
public:
	Array()
	{
		osnova = 0;
		duzina = 0;
		polje = NULL;
	}
	Array(int d, int o)
	{
		osnova = o;
		duzina = d;
		polje = new int[duzina];
	}
	Array(int d)
	{
		osnova = 0;
		duzina = d;
		polje = new int[duzina];
	}
	~Array()
	{
		delete[] polje;
	}
	void print()
	{
		for (int i = 0; i < duzina; i++)
			cout << "polje [" << i << "] = " << polje[i] << endl;
	}
	int* getData()
	{
		return polje;
	}
	int getLength()
	{
		return duzina;
	}
	int& operator [] (int index)
	{
		int offset = index - osnova;
		if (offset >= duzina)
			throw "Preso si duzinu niza";
		return polje[offset];
	}
	void setAt(int index, int el)
	{
		int offset = index - osnova;
		if (offset >= duzina)
			throw "Preso si duzinu niza";
		polje[offset] = el;
	}
	int getAt(int index)
	{
		int el;
		int offset = index - osnova;
		if (offset >= duzina)
			throw "Ne postoji ta pozicija";
		return el = polje[offset];
	}
	void setLength(int Novaduzina)
	{
		if (duzina != Novaduzina)
		{		
			int* NovoPolje = new int[Novaduzina];
			int min = duzina;
			if (min > Novaduzina)
				min = Novaduzina;
			for (int i = 0; i < min; i++)
				NovoPolje[i] = polje[i];
			delete [] polje;
			polje = NovoPolje;
		}
	}
};