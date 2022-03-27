#include"Polinom.h"
#include <iostream>
using namespace std;
void main()
{
	Polinom P1(2);
	P1.Coef(0,1);
	P1.Coef(1,2);
	P1.Coef(2,2);
	//P1.Coef(3,5);
	//P1.Coef(4,1);

	P1.stampaj();
	Polinom P2(1);
	P2.Coef(0,1);
	P2.Coef(1,2);
	//P2.Coef(2,2);
	P2.stampaj();

	Polinom P3;
	Polinom R;
	R=P3.podeli(P1,P2);

	cout<<"Rezultat deljenja:"<<"\n";
	P3.stampaj();
	cout<<"Ostatak:"<<endl;
	R.stampaj();
	
}