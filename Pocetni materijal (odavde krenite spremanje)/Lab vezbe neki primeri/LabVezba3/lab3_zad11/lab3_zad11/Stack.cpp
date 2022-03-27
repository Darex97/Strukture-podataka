#include "Stack.h"
#include <cstring>
#include <iostream>
using namespace std;

Stack::Stack(int a)
{
	n=a;
	niz= new char[n];
	top= -1;
}

Stack::~Stack(void)
{
	delete [] niz;
}

void Stack::push(char c)
{
	if (top==n-1)
		throw "stack overflow";
	niz[++top]=c;
}
char Stack::pop()
{
	if(top==-1)
		throw "stack underflow";
	return niz[top--];
}

char Stack::getTop()
{
	if(top==-1)
		throw "stack underflow";
	return niz[top];
}

int Stack::prioritet(char c)
{
	int p=0;
	if(c=='+' || c== '-')
		p=1;
	if(c=='*' || c== '/')
		p=2;
	if(c=='^')
		p=3;
	return p;
}

void Stack::uPostfix(char* s)
{
	for(int i=0; i < (int)strlen(s); i++)
	{
		char pom=s[i];
		switch (pom)
		{
		case '(':
			push(pom);
			break;
		case ')':
			{
				char c;
				while((!isEmpty()) && ((c=pop())!='('))
					cout << c;
			}
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			{
				if((!isEmpty()) && (prioritet(pom)<=prioritet(getTop())))
				{
					cout << pop();
				}
				push(pom); 
			}
			break;
		default:
			cout << pom;
		}
	}
	while(!isEmpty())
		cout << pop();
}