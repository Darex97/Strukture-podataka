// cvor.h: interface for the cvor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CVOR_H__C6137EF4_7008_4A6C_B7C7_05586BBD4534__INCLUDED_)
#define AFX_CVOR_H__C6137EF4_7008_4A6C_B7C7_05586BBD4534__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream.h>

class cvor  
{
public:
	cvor();
	cvor(int in, cvor* nx) 
	{
		info = in;
		next = nx;
	};
	virtual ~cvor();
	int info;
	cvor* next;


};

#endif // !defined(AFX_CVOR_H__C6137EF4_7008_4A6C_B7C7_05586BBD4534__INCLUDED_)
