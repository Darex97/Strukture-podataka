// SLLNode.h: interface for the SLLNode class.
//Status OK!
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SLLNODE_H__DE6E7E8B_BCF7_46E4_BCE6_79AF64F4039C__INCLUDED_)
#define AFX_SLLNODE_H__DE6E7E8B_BCF7_46E4_BCE6_79AF64F4039C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>
class SLLNode  
{
public:
	T info;
	SLLNode<T> *next;
public:
	SLLNode(){ next = NULL;}
	SLLNode(T i){ info = i; next = NULL;}
	SLLNode(T i, SLLNode<T>* n){
		info = i;
		next = n;
	}
	virtual ~SLLNode(){};
	T print(){ return info;}
	bool isEqual(T el){ return el == info;}
};

#endif // !defined(AFX_SLLNODE_H__DE6E7E8B_BCF7_46E4_BCE6_79AF64F4039C__INCLUDED_)
