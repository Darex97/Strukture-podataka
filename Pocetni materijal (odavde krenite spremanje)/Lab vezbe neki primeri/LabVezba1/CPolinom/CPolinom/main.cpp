#include "Polinom.h"
#include <iostream>
using namespace std;


void main()
{
	CPolinom p1(3);
	CPolinom p2(2);
	p1.Coef(3,2);
	p1.Coef(2,2);
	p1.Coef(1,3);
	p1.Coef(0,4);
	p1.print();
	p2.Coef(2,3);
	p2.Coef(0, 4);
	p2.print();
	CPolinom p3(p2.Add(p1, p2));
	p3.print();


}