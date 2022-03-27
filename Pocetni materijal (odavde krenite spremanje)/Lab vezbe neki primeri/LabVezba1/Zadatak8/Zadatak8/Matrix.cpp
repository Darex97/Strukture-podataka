#include "Matrix.h"
#include<iostream>
using namespace std;


CMatrix::CMatrix()
{
}
CMatrix::CMatrix(int m,int n)
{
	this->rows=m;
	this->columns=n;

	matrix=new double*[rows];
	for (int i=0;i<rows;i++)
		this->matrix[i]=new double[columns];
	for (int i=0;i<rows;i++)
		for (int j=0;j<columns;j++)
			this->matrix[i][j]=0;
}
void CMatrix::SetAt(int i,int j,double val)
{
	if (this->matrix[i][j] != 0)
		this->matrix[i][j]=val;
	else
		cout<<"mesto je popunjeno."<<endl;
} 
void CMatrix::SetRow(double* val,int n)
{
	if (n <= this->columns*this->rows)
	{
		int i=0;
		int j=0;
		for (int s=0;s<n;s++)
		{
			if (j<this->columns-1)
			{
				this->matrix[i][j]=val[s];
				j++;
			}
			else 
			{
				this->matrix[i][j]=val[s];
				i++;
				j=0;
			}
		}
	}
	else
		throw "Br el niza je veci od broja elemenata matrice.";
}
void CMatrix::SetCol(double* val,int n)
{
	if (n <= this->columns*this->rows)
	{
		int i=0;
		int j=0;
		for (int s=0;s<n;s++)
		{
			if (i<this->rows-1)
			{
				this->matrix[i][j]=val[s];
				i++;
			}
			else 
			{
				this->matrix[i][j]=val[s];
				j++;
				i=0;
			}
		}
	}
	else
		throw "Br el niza je veci od broja elemenata matrice.";
}
CMatrix CMatrix::Mul(CMatrix mat)
{
	if (this->columns == mat.rows)
	{
		CMatrix MAT(this->rows,mat.columns);
		for (int i=0;i<this->rows;i++)
		{
			for (int j=0;j<mat.columns;j++)
				for (int k=0;k<mat.rows;k++)
					MAT.matrix[i][j]+=this->matrix[i][k]*mat.matrix[k][j];
		}
		return MAT;
	}
	else
		throw "Nemoguce pomnoziti.";
}
void CMatrix::stampaj()
{
	cout<<"Matrica:"<<endl;
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<columns;j++)
			cout<<this->matrix[i][j]<<" ";
		cout<<endl;
	}
}
CMatrix::~CMatrix()
{
}
