#include"Polinom.h"
#include<iostream>
using namespace std;

void main()
{
	Polinom P1(4);
	P1.stampaj();
	int no;
	cout<<"Unesi brojno stanje koeficijenata:"<<endl;
	cin>>no;

	cout<<"Unesi zeljene stepene(indexi za koeficijente):"<<endl;
	int* exp= new int[no];

	for (int i=0;i<no;i++)
		cin>>exp[i];
	
	cout<<"Unesi koeficijente:"<<endl;
	double* coef=new double[no];

	for (int i=0;i<no;i++)
		cin>>coef[i];

	P1.Koef(exp,coef,no);
	P1.stampaj();

	(P1.oduzmi(P1)).stampaj();



}