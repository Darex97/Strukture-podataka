// StatDLList.h: interface for the StatDLList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATDLLIST_H__6A68250F_A2E8_4731_9D0E_D3AE9189716A__INCLUDED_)
#define AFX_STATDLLIST_H__6A68250F_A2E8_4731_9D0E_D3AE9189716A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class StatDLList  
{
	int *info;
	int *dlink;
	int *llink;
	int LRMP, HEAD,brup, maxv;
public:
	StatDLList(int);
	virtual ~StatDLList();
	void prikazi();
	void AdHead();
	void brisi(int);
};

#endif // !defined(AFX_STATDLLIST_H__6A68250F_A2E8_4731_9D0E_D3AE9189716A__INCLUDED_)
