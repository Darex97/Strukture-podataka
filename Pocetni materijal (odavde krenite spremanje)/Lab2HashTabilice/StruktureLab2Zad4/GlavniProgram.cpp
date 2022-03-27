#include"HashTable.h"
void main()
{
	try 
	{
		HashTable Table(10);
		HashObject o1(615155770, "Darko");
		HashObject o2(91234567, "Milos");
		HashObject o3(123456543, "Mara");
		HashObject o4(65433453, "Jovica");
		Table.insert(o1);
		Table.insert(o2);
		Table.insert(o3);
		Table.insert(o4);
		Table.printAll();
		//Table.withdraw(65433453);
		//cout << "Nakon brisanja Jovice: " << endl;
		//Table.printAll();


	}
	catch (char* izuzetak)
	{
		cout << izuzetak << endl;
	}
}