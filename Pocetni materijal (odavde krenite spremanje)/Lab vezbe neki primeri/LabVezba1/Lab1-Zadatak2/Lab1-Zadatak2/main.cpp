#include"Polinom.h"
#include<iostream>
using namespace std;

void main()
{
	Polinom P1(4);
	Polinom P2(3);
	int no;
	cout<<"Unesi broj koeficijenata:"<<endl;
	cin>>no;
	int* exp;
	exp=new int[no];
	cout<<"Unesi zeljene stepene:"<<endl;
	for (int i=0;i<no;i++)
		cin>>exp[i];
	double* coef;
	coef=new double[no];
	cout<<"Unesi zeljene koeficijente:"<<endl;
	for (int i=0;i<no;i++)
		cin>>coef[i];
	P1.Coefs(exp,coef,no);
	P1.stampaj();
	delete [] coef;
	delete [] exp;


	cout<<"Unesi broj koeficijenata:"<<endl;
	cin>>no;
	exp=new int[no];
	cout<<"Unesi zeljene stepene:"<<endl;
	for (int i=0;i<no;i++)
		cin>>exp[i];
	coef=new double[no];
	cout<<"Unesi zeljene koeficijente:"<<endl;
	for (int i=0;i<no;i++)
		cin>>coef[i];
	P2.Coefs(exp,coef,no);
	P2.stampaj();

	delete [] coef;
	delete [] exp;

	Polinom P3;

	P3.Sub(P1,P2);
	P3.stampaj();

}