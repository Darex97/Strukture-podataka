#pragma once
#include "Node.h"
class CPolynomLL {
public:
	Node *head;

	CPolynomLL()
	{
		head = NULL;
	}
	void Coef(int x, double y)
	{
		head = new Node(x, y, head);
	}
	CPolynomLL* add(CPolynomLL &p)
	{
		Node *pom1 = this->head;
		Node *pom2 = p.head;
		CPolynomLL *nova = new CPolynomLL();
		while (pom1 != 0 && pom2 != 0)
		{

			if (pom1->exp>pom2->exp)
			{
				nova->Coef(pom1->exp, pom1->coef);
				cout << nova->head->coef << "x^" << nova->head->exp;
				if (pom1->next != NULL)
					cout << "+";

				pom1 = pom1->next;
			}
			else if (pom1->exp<pom2->exp)
			{
				nova->Coef(pom2->exp, pom2->coef);
				cout << nova->head->coef << "x^" << nova->head->exp;
				if (pom2->next != NULL)
					cout << "+";

				pom2 = pom2->next;
			}
			else
			{
				nova->Coef(pom2->exp, pom2->coef + pom1->coef);
				
				cout << nova->head->coef << "x^" << nova->head->exp;
				if (pom2->next != NULL)
					cout << "+";
				pom1 = pom1->next;
				pom2 = pom2->next;
			}
			if (pom1 == 0)
			while (pom2 != 0)
			{
				nova->Coef(pom2->exp, pom2->coef);
				cout << nova->head->coef << "x^" << nova->head->exp;
				if (pom2->next != NULL)
					cout << "+";

				pom2 = pom2->next;
			}
			else if (pom2 == 0)
			while (pom1 != 0)
			{
				nova->Coef(pom1->exp, pom1->coef);
				cout << nova->head->coef << "x^" << nova->head->exp;
				if (pom1->next != NULL)
					cout << "+";
				pom1 = pom1->next;

			}
		}
		return nova;

	}
	void print()
	{
		Node* pom = head;
		while (pom != NULL)
		{
			cout << pom->coef << "x^" << pom->exp;
			if (pom->next != NULL)
				cout << "+";
			pom = pom->next;
		}
		cout << endl;
	}



};
