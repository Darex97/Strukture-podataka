#include"Polynom.h"
#include"SLLNode.h"

void main()
{
	CPolynom *P1=new CPolynom();
	P1->AddToTail(3,3);
	P1->AddToTail(3,2);
	P1->PRINT();
	CPolynom *P2=new CPolynom();
	P2->Add(2,3);
	P2->Add(2,4);
	P2->PRINT();
	CPolynom *P3=new CPolynom();
	P3->Merge(P1,P2);
	P3->PRINT();
}