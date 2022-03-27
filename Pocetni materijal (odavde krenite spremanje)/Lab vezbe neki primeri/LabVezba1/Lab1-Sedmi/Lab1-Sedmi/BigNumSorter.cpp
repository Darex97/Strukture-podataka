#include "BigNumSorter.h"
#include<iostream>
using namespace std;

CBigNumSorter::CBigNumSorter(void)
{
	row=column=0;
}

CBigNumSorter::CBigNumSorter(int n,int m)
{
	row=n;
	column=m;
	matrix=new int*[n];
	for(int i=0;i<n;i++)
		matrix[i]=new int[m];
	for(int i=0;i<n;i++)
		matrix[i][this->column-1]=-1;
}
void CBigNumSorter::Add(int *num,int n)
{
	if(this->column>=n)
	{
		int i=0;
	while(this->matrix[i][this->column-1]!=-1)
	{
		i++;
	}
	if(i<=this->row-1)
	{
		for(int k=0;k<this->column;k++)
			this->matrix[i][k]=0;
	int j=this->column-1;
	int h=n-1;
	while(h>-1)
	{
		this->matrix[i][j]=num[h];
		j--;
		h--;
	}
	}
	else
		throw "Matrica popunjena";
	}
	else
		throw "Broj je duzi od ocekivanog";
}
void CBigNumSorter::Sort()
{
	int temp,a=1;
	for(int j=this->column-1;j>=0;j--)
	{
		for(int k=0;k<this->row;k++)
			for(int i=0;i<this->row-1;i++)
		{
			if(this->matrix[i][j]>this->matrix[i+1][j])
			{
				for(int h=0;h<this->column;h++)
				{
					temp=this->matrix[i][j];
					this->matrix[i][j]=this->matrix[i+1][j];
					this->matrix[i+1][j]=temp;
				}
			}
		}
			cout<<"Iteracija br:"<< a<<endl;
		(*this).stampaj();
		cout<<endl;
		a++;
	}
}
void CBigNumSorter::stampaj()
{
	for(int i=0;i<this->row;i++)
	{
		for(int j=0;j<this->column;j++)
		{
			cout<<this->matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
CBigNumSorter::~CBigNumSorter(void)
{
}
