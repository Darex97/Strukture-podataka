#include "Array.h"

void main()
{
	try {
		Array a(10);
		for (int i = 0; i < 10; i++)
		{
			a[i] = i + 1;
		}
		a.setAt(5, 16);
		a.print();
		int b = a.getAt(3);
		cout << b << endl;
		a.setAt(13, 33);
		//a.setLength(8);
		//a.print();
	}
	catch (char *s)
	{
		cout << s << endl;
	}
}