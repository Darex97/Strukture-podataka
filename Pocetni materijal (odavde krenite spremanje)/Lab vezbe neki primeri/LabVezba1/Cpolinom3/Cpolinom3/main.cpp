#include"Polinom.h"
#include<iostream>
using namespace std;

void main()
{
	Polinom P1(4);

	int no;
	cout<<"Broj koeficijenata za unos:"<<endl;
	cin>>no;

	int* exp=new int[no];
	cout<<"Zeljeni stepeni za smestaj koeficijenata:"<<endl;
	for (int i=0;i<no;i++)
		cin>>exp[i];

	double* coef=new double[no];
	cout<<"Unesi koeficijente:"<<endl;
	for (int i=0;i<no;i++)
		cin>>coef[i];

	P1.Koef(exp,coef,no);
	P1.stampaj();

	
	delete [] exp;
	delete [] coef;


	Polinom P2(3);
	cout<<"Broj koeficijenata za unos:"<<endl;
	cin>>no;

	int* exp2=new int[no];
	cout<<"Zeljeni stepeni za smestaj koeficijenata:"<<endl;
	for (int i=0;i<no;i++)
		cin>>exp2[i];

	double* coef2=new double[no];
	cout<<"Unesi koeficijente:"<<endl;
	for (int i=0;i<no;i++)
		cin>>coef2[i];

	P2.Koef(exp2,coef2,no);
	P2.stampaj();	

	Polinom P3;
	P3.pomnozi(P1,P2);
	P3.stampaj();
}