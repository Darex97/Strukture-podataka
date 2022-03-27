#include"PolynomLL.h"
#include"SLLNode.h"
#include<iostream>
using namespace std;

void main()
{
	try
	{
		CPolynomLL P1;
		P1.Coef(6,4);
		P1.Coef(2,3);
		P1.Coef(1,2);
		P1.Coef(5,0);
		P1.Coef(3,1);
		P1.PRINT();

		CPolynomLL P2;
		
		P2.Coef(2,3);
		P2.Coef(1,2);
		P2.Coef(5,0);
		P2.Coef(3,1);
		P2.PRINT();

		CPolynomLL P3;
		P3.Mul(P1,P2);
		P3.PRINT();
	/*	CPolynomLL P3;
		P1.head=(P3.Add(P2,P1))->head;
		P1.PRINT();*/

		
	}
	catch(char* message)
	{
		cout<<message<<endl;
	}
}