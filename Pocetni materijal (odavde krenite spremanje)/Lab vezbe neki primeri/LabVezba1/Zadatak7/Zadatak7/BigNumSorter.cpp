#include "BigNumSorter.h"
#include<iostream>
using namespace std;


CBigNumSorter::CBigNumSorter()
{
	rows=columns=0;
}
CBigNumSorter::CBigNumSorter(int m/*broj brojeva*/,int n/*velicina broja*/)
{
	this->rows=m;
	this->columns=n;

	matrix=new int*[rows];
	for (int i=0;i<rows;i++)
		matrix[i]=new int[columns];
	for (int i=0;i<rows;i++)
		for (int j=0;j<columns;j++)
			this->matrix[i][j]=0;

	for (int i=0;i<rows;i++)
		this->matrix[i][this->columns-1]=-1;
}
void CBigNumSorter::Sort()
{



}
void CBigNumSorter::Add(int* num,int n)
{
	if (n<=this->columns)
	{
		int i=0;
		while (i<this->rows && this->matrix[i][this->columns-1] != -1 )
			i++;
		if (i==this->rows)
			throw "Matrica je puna.";
		else
		{
			int s=this->columns-1;
			for (int j=n-1;j>=0;j--)
			{
				this->matrix[i][s]=num[j];
				s--;
			}
		}
	}
	else
		throw "broj je veci od duzine matrice.";
}
void CBigNumSorter::stampaj()
{
	for (int i=0;i<this->rows;i++)
	{
		for (int j=0;j<this->columns;j++)
			cout<<this->matrix[i][j]<<" ";
		cout<<endl;
	}

}
CBigNumSorter::~CBigNumSorter(void)
{
}
