#pragma once
class CMatrix
{
private:
	int rows;
	int columns;
	double** matrix;
public:
	CMatrix();
	CMatrix(int m,int n);
	void SetAt(int i,int j,double val);
	void SetRow(double* val,int n);
	void SetCol(double* val,int n);
	CMatrix Mul(CMatrix mat);
	void stampaj();
	~CMatrix();
};

