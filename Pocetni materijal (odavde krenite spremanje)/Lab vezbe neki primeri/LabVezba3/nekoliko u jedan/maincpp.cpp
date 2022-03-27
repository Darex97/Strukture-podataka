#pragma once
#include <iostream>
#include "Node.h"
#include "Stack.h"
#include "StackAsLListed.h"
#include "QueueAsLListed.h"
using namespace std;
void main()
{
	StackAsLListed n;
	for (int i = 0; i <4; i++)
	{
	   n.push(i*i);
	}
	/*if (s1.top==NULL)
		cout<<"nula";
	else 
		cout<<s1.top->info;*/
	//int p=;
	//int p=s1.getTop();
	//cout<<p<<endl;
	//try {
	//n.print();
	//cout<<endl;
	StackAsLListed m;
	CopyStack(n,m);
	m.print();
	n.print();
	//}
/*	QueueAsLListed s2;
	for (int i = 0; i < 7 ; i++)
	{
		s2.enqueue(i*i+5);
	}
	s2.print();*/
	system("pause");
}