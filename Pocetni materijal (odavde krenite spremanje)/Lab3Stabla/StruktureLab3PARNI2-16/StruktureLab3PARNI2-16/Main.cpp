#include"StatickoStablo.h"
void main()
{
	StatickoStablo s1(4);
	try
	{
		s1.ubaci(3);
		s1.ubaci(1);
		s1.ubaci(2);
		s1.ubaci(6);
		s1.ubaci(5);
		s1.ubaci(9);
		s1.ubaci(10);
	}
	catch (char* izuzetak)
	{
		cout << izuzetak << endl;
	}
	cout << "Inorder stabla: " << endl;
	s1.prikazi();
	cout << "Visina stabla je: " << s1.visina() << endl;
	cout << "Moment stabla je: " << s1.moment() << endl;
	cout << "Tezina stabla je: " << s1.tezina() << endl;
	cout << "Nivo sa najvise cvorova prvog stabla je: " << s1.nivoSaNajviseCvorova() << endl;

	s1.brisanjeListova();
	cout << "Inorder stabla posle brisanja listova: ";
	s1.prikazi();

	s1.mirrorKopija();
	cout << "Inorder mirror kopije stabla : ";
	s1.prikazi();

	StatickoStablo* drugoStablo = new StatickoStablo(3);
	StatickoStablo prvoStablo(4);

	prvoStablo.ubaci(5);
	prvoStablo.ubaci(4);
	prvoStablo.ubaci(2);
	prvoStablo.ubaci(1);
	prvoStablo.ubaci(7);
	prvoStablo.ubaci(3);
	prvoStablo.ubaci(6);

	drugoStablo->ubaci(8);
	drugoStablo->ubaci(1);
	drugoStablo->ubaci(10);
	drugoStablo->ubaci(9);

	cout << "Inorder drugog stabla: ";
	drugoStablo->prikazi();

	prvoStablo.spajanjeStabala(*drugoStablo);
	delete drugoStablo;

	cout << "Inorder spojenih stabala: ";
	prvoStablo.prikazi();



}