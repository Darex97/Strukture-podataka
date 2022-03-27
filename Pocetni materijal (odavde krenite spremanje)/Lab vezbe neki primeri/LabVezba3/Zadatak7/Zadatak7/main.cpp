#include"DoubleStack.h"


void main()
{
	try
	{
		DoubleStack S(6);
		S.push(3,1);
		S.push(5,0);
		S.push(4,0);
		S.push(7,1);
		S.print();
		S.pop(1);
		S.pop(0);
		S.print();
		S.pop(1);
		S.pop(1);
	}
	catch(char *message)
	{
		cout<<message<<endl;
	}
}