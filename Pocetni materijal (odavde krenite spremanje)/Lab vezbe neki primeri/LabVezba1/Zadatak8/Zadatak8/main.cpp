#include"Matrix.h"
#include<iostream>
using namespace std;

void main()
{
	try{
	CMatrix mat1(2,2);
	mat1.stampaj();
	
	int n;
	double* val;
	cout<<"Unesi broj elemenata:"<<endl;
	cin>>n;
	val=new double[n];
	cout<<"Unesi elemente:"<<endl;
	for (int i=0;i<n;i++)
		cin>>val[i];
	mat1.SetRow(val,n);
	mat1.stampaj();
	delete [] val;

	CMatrix mat2(2,2);
	cout<<"Unesi broj elemenata:"<<endl;
	cin>>n;
	val=new double[n];
	cout<<"Unesi elemente:"<<endl;
	for (int i=0;i<n;i++)
		cin>>val[i];
	
	mat2.SetRow(val,n);
	mat2.stampaj();

	(mat1.Mul(mat2)).stampaj();

	}
	catch(char* message)
	{
		cout<<message<<endl;
	}
}