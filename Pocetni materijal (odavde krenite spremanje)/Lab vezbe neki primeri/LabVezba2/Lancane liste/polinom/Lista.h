// Lista.h: interface for the Lista class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTA_H__8C5C25F2_0EEE_4CA1_8096_C41CCBC327EE__INCLUDED_)
#define AFX_LISTA_H__8C5C25F2_0EEE_4CA1_8096_C41CCBC327EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Lista  
{
private:
	int exp;
	int koef;
	Lista* sledeci;
	Lista* head;
	Lista* tail;
public:
Lista();
	void Unesi(int n);
	void Prikazi();
	void addTohead(int e,int k);
	void addTotail(int e,int k);

};

#endif // !defined(AFX_LISTA_H__8C5C25F2_0EEE_4CA1_8096_C41CCBC327EE__INCLUDED_)
