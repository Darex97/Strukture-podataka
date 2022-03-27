// StatSLList.h: interface for the StatSLList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATSLLIST_H__345B3FD3_91E0_4C23_BFCB_ADCADE013BE3__INCLUDED_)
#define AFX_STATSLLIST_H__345B3FD3_91E0_4C23_BFCB_ADCADE013BE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class StatSLList  
{
	int* link;
	int* info;
	int lrmp, header, brup, maxvel;
public:
	StatSLList(int);
	virtual ~StatSLList();
	void adHead(int);
	void bubbleSort();
	void prikazi();
};

#endif // !defined(AFX_STATSLLIST_H__345B3FD3_91E0_4C23_BFCB_ADCADE013BE3__INCLUDED_)
