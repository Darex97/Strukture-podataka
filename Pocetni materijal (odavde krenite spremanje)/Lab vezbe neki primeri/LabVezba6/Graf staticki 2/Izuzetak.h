// Izuzetak.h: interface for the Izuzetak class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IZUZETAK_H__391A104C_676E_4B7D_A176_6B881D44C731__INCLUDED_)
#define AFX_IZUZETAK_H__391A104C_676E_4B7D_A176_6B881D44C731__INCLUDED_
//definise ako nije definisana
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<string.h>
#include<iostream.h>

class Izuzetak  
{
	char *s;


public:
	Izuzetak(char *s1)
	{
		s=new char[50];
		strcpy(s,s1);
	}

	Izuzetak(Izuzetak& d)
	{
		d=new char[50];
		strcpy(s,d.s);
	}
	virtual ~Izuzetak()
	{
		delete [] s;
	}
	void prikazi()
	{
		cout<<s<<endl;
	}

};

#endif // !defined(AFX_IZUZETAK_H__391A104C_676E_4B7D_A176_6B881D44C731__INCLUDED_)
