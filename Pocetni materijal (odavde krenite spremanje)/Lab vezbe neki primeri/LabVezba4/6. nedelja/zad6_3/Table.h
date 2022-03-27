// Table.h: interface for the Table class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLE_H__466B66BF_0F9D_4BD2_9E4F_8367FF22B648__INCLUDED_)
#define AFX_TABLE_H__466B66BF_0F9D_4BD2_9E4F_8367FF22B648__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Object.h"

class Table  
{
	unsigned int duzina;
	unsigned int brup;
	Object *niz;//niz hash objekata
	unsigned int f(char*);
	unsigned int h(Object);
	unsigned int g(unsigned int);
public:
	Table(unsigned int);
	virtual ~Table();
	void display();
	void Insert(Object);
	Object find(char*);
	void withdraw(char*);
	inline unsigned int getLenght(){ return duzina;}
	inline double getLoadFactor(){ return (double)brup/(double)duzina;}

};

#endif // !defined(AFX_TABLE_H__466B66BF_0F9D_4BD2_9E4F_8367FF22B648__INCLUDED_)
