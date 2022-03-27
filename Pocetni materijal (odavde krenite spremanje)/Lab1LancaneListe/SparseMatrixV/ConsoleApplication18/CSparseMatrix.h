#pragma once
#include "NodeElement.h"
#include <iostream>
using namespace std;
//#include <stddef.h>

template <class T>
class CSparseMatrix
{
	int m, n; // dimenzije
	NodeElement<T> ** vrste, ** kolone;

public:
	CSparseMatrix()
	{
		m = n = 0;
		vrste = kolone = 0;
	}

	CSparseMatrix(int a, int b)
	{
		m = a;
		n = b;
		vrste = new NodeElement<T>*[m];
		for (int i = 0; i < m; i++)
			vrste[i] = NULL;

		kolone = new NodeElement<T>*[n];
		for (int i = 0; i < n; i++)
			kolone[i] = NULL;
	}

	void SetAt(T el, int i, int j)// koordinate se zadaju normalno(prvi element 1,1)
	{
		NodeElement<T> * a = new NodeElement<T>(el, i, j);

		if (vrste[i - 1] == NULL)
		{
			vrste[i - 1] = a;
			a->linkV = NULL;
		}
		else
		{
			NodeElement<T> * tmp = vrste[i - 1];//prvi u datoj vrsti TRENUTNO
			NodeElement<T> * tmp2;

			if (a->y > tmp->y)//Da li je broj kolone unesenog veci od broja kolone trenutnog
				//proveravamo da znamo da li treba link vrste da prebacimo na njega
				//i to cemo uraditi u else grani
			{
				while (tmp != NULL && a->y > tmp->y)
					tmp = tmp->linkV;
				if (tmp == NULL)
				{
					for (tmp2 = vrste[i - 1]; tmp2->linkV != NULL; tmp2 = tmp2->linkV);
					tmp2->linkV = a;
					a->linkV = NULL;
				}
				else
					//if i else grana su ti identicne, s tim sto u poslednjim linijama koda za
					//a->linkV vezujes NULL u if-u, a tmp u else grani.
				{
					for (tmp2 = vrste[i - 1]; tmp2->linkV != tmp; tmp2 = tmp2->linkV);
					tmp2->linkV = a;
					a->linkV = tmp;
				}
			}
			else
			{
				vrste[i - 1] = a;
				a->linkV = tmp;
			}

		}

		if (kolone[j - 1] == NULL)
		{
			kolone[j - 1] = a;
			a->linkK = NULL;
		}
		else
		{
			NodeElement<T> * tmp = kolone[j - 1];
			NodeElement<T> * tmp2;
			if (a->x > tmp->x)
			{
				while (tmp != NULL && a->x > tmp->x)//ista fora je sa ovim delom ovde
					//ako ti je vrsta dodatog nakon vrste trenutnog onda
					//ces da prelancas sa nekim elementom
					//a ako nije to slucaj
					// onda ces da ga ulancas na pocetak niza pointera kolona.
					tmp = tmp->linkK;
				if (tmp == NULL)
				{
					for (tmp2 = kolone[j - 1]; tmp2->linkK != NULL; tmp2 = tmp2->linkK);
					tmp2->linkK = a;
					a->linkK = NULL;
				}
				else
				{
					for (tmp2 = kolone[j - 1]; tmp2->linkK != tmp; tmp2 = tmp2->linkK);
					tmp2->linkK = a;
					a->linkK = tmp;

				}
			}
			else
			{
				kolone[j - 1] = a;
				a->linkK = tmp;
			}

		}

	}
	void print()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (vrste[i] == NULL)//ako nam vrsta pocinje nulom
					//istampacemo m puta 0
					cout << 0 << " ";
				else
				{
					if (kolone[j] != NULL)
					{
						NodeElement<T> * tmp = kolone[j];
						while (tmp->linkK != NULL && tmp->x - 1 != i)
						{
							tmp = tmp->linkK;
						}
						if (tmp->x - 1 == i)
							cout << tmp->element << " ";
						else
						{
							cout << 0 << " ";
						}
					}
					else cout << 0 << " ";
				}
			}
			cout << endl;
		}
	}

	~CSparseMatrix()
	{
		for (int i = 0; i < m; i++)
		{
			if (vrste[i] != NULL)
				delete vrste[i];
		}
		delete vrste;
		delete kolone;
	}
	T GetAt(int i, int j)
	{
		if (i<0 || i>m || j<0 || j>m)
		{
			throw "Uneli ste indekse van opsega.";
		}
		NodeElement<T>* tmp;
		for (tmp = vrste[i - 1];tmp->y != j;tmp = tmp->linkV);

			return tmp->element;
		
		

	}
	
};