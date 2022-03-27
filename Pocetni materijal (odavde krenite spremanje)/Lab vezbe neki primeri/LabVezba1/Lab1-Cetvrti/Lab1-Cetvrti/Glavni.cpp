#include"Cpolynom.h"
#include<iostream>
using namespace std;
void main()
{
	try
	{
	Cpolynom Prvi(4);
	Prvi.Coef(0,4);
	Prvi.Coef(1,2);
	Prvi.Coef(2,3);
	Prvi.Coef(3,1);
	Prvi.Coef(4,5);

	Cpolynom Drugi(2);
	Drugi.Coef(0,3);
	Drugi.Coef(1,2);
	Drugi.Coef(2,4);

	Cpolynom Treci;
	Cpolynom R;
	R=Treci.Div(Prvi,Drugi);
	Treci.stampaj();
	R.stampaj();
	R=Treci.Div(Drugi,Prvi);
	}
	catch(char* n)
	{
		cout<<n<<endl;
	}
}/*5*x^4+x^3+3*x^2+2*x+4
	4*x^2+2*x+3*/