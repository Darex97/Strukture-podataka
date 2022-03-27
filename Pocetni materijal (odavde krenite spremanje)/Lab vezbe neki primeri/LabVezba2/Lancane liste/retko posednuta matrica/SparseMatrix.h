// SparseMatrix.h: interface for the SparseMatrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPARSEMATRIX_H__1149BBD7_CD30_4ABF_916B_EE08BFA71531__INCLUDED_)
#define AFX_SPARSEMATRIX_H__1149BBD7_CD30_4ABF_916B_EE08BFA71531__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Node.h"

class SparseMatrix  
{
	double load_factor;
	int noElements;
	Node** colums;
	Node** rows;
	unsigned int size;
public:
	SparseMatrix(int);
	virtual ~SparseMatrix();
	void addElement(int, int, int);
	int deleteElement(int, int);
	void display();
//	void updateLoadFactor();
	bool isEmpty();
	double getLoadFactor();
};

#endif // !defined(AFX_SPARSEMATRIX_H__1149BBD7_CD30_4ABF_916B_EE08BFA71531__INCLUDED_)
