#include "UrBinStablo.h"
void main()
{
	UrBinStablo b,c;
	for(int i=1;i<100;i+=10)
	{
		int a=i%23;
		b.ubaciCvor(a);
		c.ubaciCvor((-i));
	}
	b.spojiSa(c.root);
	b.prodjiStablo(b.root);
	cout<<endl;
	b.brisanjeKopiranjem(-71);
	b.prodjiStablo(b.root);
	cout<<endl;
	system("pause");

}
