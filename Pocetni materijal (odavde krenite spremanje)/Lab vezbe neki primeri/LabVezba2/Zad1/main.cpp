#include <iostream>
using namespace std;
#include "klase.h"
int main()
{
	CPolynom x,y;
	x.Coef(1,1);
	x.Coef(2,3);
	x.Coef(3,5);
	cout<<"Prvi polinom:"<<endl;
	x.stampaj();
	y.Coef(2,1);
	y.Coef(7,3);
	y.Coef(3,4);
	cout<<"Drugi polinom:"<<endl;
	y.stampaj();
	CPolynom z;
	z=Add(x,y);
	cout<<"Zbir polinoma:"<<endl;
	z.stampaj();
	system("pause");
}