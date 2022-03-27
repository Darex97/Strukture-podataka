#include <iostream>
#include <math.h>

using namespace std;

#include "CPolynom.h"
#include "DSException.h"

CPolynom::CPolynom()
{
	this->order = 0;
	this->coefs = new double{ 0.0 };
}

void CPolynom::AllocateMemory(int order)
{
	this->order = order;
	this->coefs = new double[this->order + 1];
}

CPolynom::CPolynom(int order)
{
	this->AllocateMemory(order);

	for (int i = 0; i <= this->order; i++)
	{
		this->coefs[i] = 0.0;
	}
}

void CPolynom::CopyCoefs(const CPolynom& poly)
{
	for (int i = 0; i <= this->order; i++)
	{
		this->coefs[i] = poly.coefs[i];
	}
}

CPolynom::CPolynom(const CPolynom& poly)
{
	this->AllocateMemory(poly.order);

	this->CopyCoefs(poly);
}

void CPolynom::DeallocateMemory()
{
	if (this->coefs)
	{
		delete[] this->coefs;
	}
}

CPolynom::~CPolynom()
{
	this->DeallocateMemory();
}

CPolynom& CPolynom::operator=(const CPolynom& poly)
{
	if (this != &poly)
	{
		if (this->order != poly.order)
		{
			this->DeallocateMemory();

			this->AllocateMemory(poly.order);
		}

		this->CopyCoefs(poly);
	}

	return *this;
}

void CPolynom::Coef(int exp, double coef)
{
	if (exp < 0 || exp > this->order)
	{
		throw DSException("Exponent is not valid!");
	}

	this->coefs[this->order - exp] = coef;
}

CPolynom CPolynom::Add(const CPolynom& poly1, const CPolynom& poly2)
{
	if (poly1.order >= poly2.order)
	{
		CPolynom resultPoly(poly1.order);

		resultPoly.CopyCoefs(poly1);

		for (int i = poly2.order; i >= 0; i--)
		{
			resultPoly.coefs[i + (poly1.order - poly2.order)] += poly2.coefs[i];
		}

		return resultPoly;
	}
	else
	{
		CPolynom resultPoly(poly2.order);

		resultPoly.CopyCoefs(poly2);

		for (int i = poly1.order; i >= 0; i--)
		{
			resultPoly.coefs[i + (poly2.order - poly1.order)] += poly1.coefs[i];
		}

		return resultPoly;
	}
}

CPolynom CPolynom::Mul(const CPolynom& poly1, const CPolynom& poly2)
{
	int resultOrder = poly1.order + poly2.order;
	CPolynom resultPoly(resultOrder);

	for (int i = 0; i <= poly1.order; i++)
	{
		for (int j = 0; j <= poly2.order; j++)
		{
			resultPoly.coefs[i + j] += poly1.coefs[i] * poly2.coefs[j];
		}
	}

	return resultPoly;
}

void CPolynom::Print()
{
	bool isFirst = true;

	for (int i = 0; i <= this->order; i++)
	{
		if (this->coefs[i] != 0.0)
		{
			if (this->coefs[i] < 0.0)
			{
				cout << "-";
			}
			else if (!isFirst && this->coefs[i] > 0.0)
			{
				cout << "+";
			}

			if (abs(this->coefs[i]) != 1.0)
			{
				cout << abs(this->coefs[i]);
			}

			if (i != this->order)
			{
				cout << "x";

				if (i != this->order - 1)
				{
					cout << "^" << this->order - i;
				}
			}
			else
			{
				if (abs(this->coefs[i]) == 1.0)
				{
					cout << abs(this->coefs[i]);
				}
			}

			isFirst = false;
		}
	}
}