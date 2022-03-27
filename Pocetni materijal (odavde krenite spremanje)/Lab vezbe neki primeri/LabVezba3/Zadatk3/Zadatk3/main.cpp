#include"Node.h"
#include"StackAsList.h"
#include<iostream>
using namespace std;

void main()
{
	try
	{
		StackAsList S1;
		S1.push(3);
		S1.push(4);
		S1.PRINT();
		(S1.pop()).print();
		S1.PRINT();
		(S1.pop()).print();
		(S1.getTop()).print();
		S1.pop();
		S1.PRINT();
	}
	catch(char *message)
	{
		cout<<message<<endl;
	}
}