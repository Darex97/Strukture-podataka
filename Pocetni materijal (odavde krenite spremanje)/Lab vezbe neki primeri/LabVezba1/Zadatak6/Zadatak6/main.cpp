#include"C3DVec.h"
#include<iostream>
using namespace std; 

void main()
{
	C3DVec Vektor1(3,3,2);
	Vektor1.stampaj();
	C3DVec Vektor2(1,1,1);
	Vektor2.stampaj();
	cout<<"Skalarni proizvod:"<<Vektor1.Dot(Vektor2)<<endl;

	cout<<"Vektorski proizvod:"<<endl;
	(Vektor1.Cross(Vektor2)).stampaj();
}