#include "OpenScatterTable.h"

void main()
{
	try
	{
		OpenScatterTable a(10);
		HashObject o1("for");
		a.insert(o1);
		HashObject o2("while");
		a.insert(o2);
		HashObject o3("foreach");
		a.insert(o3);
		HashObject o4("float");
		a.insert(o4);
		HashObject o5("int");
		a.insert(o5);
		HashObject o6("switch");
		a.insert(o6);
		a.display();//dobro rasipanje!!!
		a.withdraw("float");
		a.display();
	}
	catch(char* ex)
	{
		cout<<ex<<endl;
	}
}