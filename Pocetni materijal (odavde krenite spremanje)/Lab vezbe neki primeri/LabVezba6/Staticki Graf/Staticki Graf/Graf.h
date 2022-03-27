#pragma once
#include "iostream"
using namespace std;

class Graf
{
public:
	int **matSus;
	int brEl;
	int maxDim;
	int* nizCvorova;
	Graf()
	{
		brEl=0;
		matSus=NULL;
	}
	Graf(int n)
	{  
		maxDim=n;
		brEl=0;
		matSus=new int*[n];
		nizCvorova=new int[n];
		for (int i = 0; i <n; i++)
		{
			matSus[i]=new int[n];
			nizCvorova[i]=0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matSus[i][j]=0;
			}
		}
	}
	void dodajCvor(int p)
	{
		
		nizCvorova[brEl]=p;
			brEl++;
	}
	void dodajVezu(int p,int k)
	{
		matSus[p][k]=1;
	}
	void stampajGraf()
	{
		for (int i = 0; i < brEl; i++)
		{
			cout<<nizCvorova[i]<<"  ";
		}
		cout<<endl;
		for (int i = 0; i < brEl; i++)
		{
			for (int j = 0; j < brEl; j++)
			{
				cout<<matSus[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
