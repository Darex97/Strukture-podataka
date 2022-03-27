#include "CPolynomLL.h"
#include <iostream>

using namespace std;

void CPolynomLL::Coef(int exp, double koef)
{
	if (isEmpty())
	{
		tail = head = new PNode(exp, koef);
	}
	else
	{
		tail->next = new PNode(exp, koef);
		tail = tail->next;
	}
}

CPolynomLL* CPolynomLL::Add(CPolynomLL poly1, CPolynomLL poly2)
{
	CPolynomLL* tmp = new CPolynomLL();
	for (PNode* tmp1 = poly1.head; tmp1 != NULL; tmp1 = tmp1->next)
	{
		PNode* tmp2;
		for (tmp2 = poly2.head; (tmp2 != NULL) && (tmp1->exp <= tmp2->exp); tmp2 = tmp2->next)
		{
			if (tmp2 != NULL && tmp1->exp == tmp2->exp)
			{
				tmp->Coef(tmp1->exp, tmp1->koef + tmp2->koef);
				break;
			}
			if (tmp2 != NULL && tmp1->exp < tmp2->exp)
				tmp->Coef(tmp2->exp, tmp2->koef);
		}
		if (tmp2 == NULL) tmp->Coef(tmp2->exp, tmp2->koef);
	}
	return tmp;

}
void CPolynomLL::printPolin()
{
	for (PNode* tmp = head; tmp != NULL; tmp = tmp->next)  tmp->print();
}


CPolynomLL::~CPolynomLL(void)
{
}
