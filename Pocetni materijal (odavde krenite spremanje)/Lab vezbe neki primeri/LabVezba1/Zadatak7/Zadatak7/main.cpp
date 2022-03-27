#include"BigNumSorter.h"
#include<iostream>
using namespace std;

void main()
{
	try
	{

		int brbrojeva;
		int vel;
		int* niz;
		cout<<"Broj velikih brojeva:"<<endl;
		cin>>brbrojeva;
		cout<<"Max br cifara u matrici:"<<endl;
		cin>>vel;

		CBigNumSorter mat(brbrojeva,vel);

		int n;
		for (int i=0;i<brbrojeva;i++)
		{
			cout<<"Broj cifara broja:"<<endl;
			cin>>n;
			niz=new int[n];
			cout<<"Unesi cifre:"<<endl;
			for (int i=0;i<n;i++)
				cin>>niz[i];
			mat.Add(niz,n);
			mat.stampaj();
			delete [] niz;
		}


		

		
		




	}
	catch(char* message)
	{
		cout<<message<<endl;
	}
}