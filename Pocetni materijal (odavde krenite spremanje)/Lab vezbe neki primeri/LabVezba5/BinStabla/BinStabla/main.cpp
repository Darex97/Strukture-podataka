#include "BinStablo.h"
void main()
{
	BinStablo b;
	for(int i=1;i<20;i+=3)
	b.ubaciCvor(i);
	b.koren->desnodete->levodete=new CvorStabla(52);
	b.koren->levodete->desnodete=new CvorStabla(18);
	b.brelemenata+=2;
	b.prodjiStablo(b.koren);
	cout<<endl;
	b.obrisiListove(b.koren,b.koren);
	cout<<endl;
	b.prodjiStablo(b.koren);
	int a=0;
	b.odrediVisinu(b.koren,0,&a);
	cout<<"\n"<<a;
	a=pow(2,a)+1;
	int* niz=new int[a];
	for(int i=0;i<=a;i++)
	{
		niz[i]=0;
	}
	b.dinUStat(b.koren,1,niz);
	cout<<endl;
	for(int i=0;i<=a;i++)
	{
		cout<<" "<<niz[i];
	}
	a=0;
	b.prebrojCvorove(b.koren,&a);
	cout<<"\n"<<a;
	system("pause");
}
