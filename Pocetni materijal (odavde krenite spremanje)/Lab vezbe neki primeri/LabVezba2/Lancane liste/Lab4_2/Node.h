// Node.h: interface for the Node class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODE_H__79AF68E3_CFE3_48F3_8DC1_FEA1672BC0B3__INCLUDED_)
#define AFX_NODE_H__79AF68E3_CFE3_48F3_8DC1_FEA1672BC0B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Node  
{
public:
	int info;
	Node* next;

	Node();
	Node(int);
	Node(int, Node*);
	virtual ~Node();
	bool isEqual(int);
	int print();
};

#endif // !defined(AFX_NODE_H__79AF68E3_CFE3_48F3_8DC1_FEA1672BC0B3__INCLUDED_)
