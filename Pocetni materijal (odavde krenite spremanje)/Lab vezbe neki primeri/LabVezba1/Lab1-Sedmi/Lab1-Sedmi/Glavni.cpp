#include"BigNumSorter.h"
#include<iostream>
using namespace std;
void main()
{
	try{
	int n,m;
	int *num;
	cout<<"Unesi koliko zelis brojeva da uneses:";
	cin>>n;
	cout<<"\nUnesi koliko najveci broj ima cifara:";
	cin>>m;
	CBigNumSorter Prvi(n,m);
	for(int i=1;i<=n;i++)
	{
	cout<<"Unesite broj cifara "<<i<<".broja:"<<endl;
	cin>>m;
	num=new int[m];
	cout<<"Unesite cifre vaseg broja:"<<endl;
	for(int j=0;j<m;j++)
		cin>>num[j];
	Prvi.Add(num,m);
	delete [] num;
	}
	Prvi.stampaj();
	cout<<endl;
	Prvi.Sort();
	}
	catch(char* n)
	{
		cout<<n;
	}
}