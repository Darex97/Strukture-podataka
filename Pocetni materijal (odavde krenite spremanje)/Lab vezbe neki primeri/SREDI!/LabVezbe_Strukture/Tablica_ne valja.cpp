#include<stdio.h>

class tablica
{
protected:
	int tab[10][3];
public:
	tablica();
	void dodavanje(int kljuc,int pod);
	void stampa();
	void trazenje(int kljuc);
};


tablica::tablica()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<3;j++)
			tab[i][j]=0;
};

void tablica::dodavanje(int kljuc,int pod)
{
	int ap,as;
	ap=kljuc%10;
	if (tab[ap][0]==0 && tab[ap][2]==0)
	{
		tab[ap][0]=kljuc;
		tab[ap][1]=pod;
		tab[ap][2]=1;
	}
	else 
	{
		as=(ap+1)%10;
		while(tab[as][2]!=0)
		{
			as=(as+1)%10;
		};
		tab[as][0]=kljuc;
		tab[as][1]=pod;
		tab[as][2]=1;
	};
	printf("\n Uneti kljuc je:%d", kljuc);
	printf("\n podatak je:%d",pod);
	return;
};

void tablica::trazenje(int kljuc)
{
	int j = kljuc%10,kraj=kljuc%10;
	if(kraj==0)
		kraj=10;
	if(tab[j][0]==kljuc){
		printf("\n trazeni kluc je: %d",tab[j][0]);
		printf("\n trazeni podatak je: %d",tab[j][1]);
	}
	j++;
	while(tab[j][0]!=kljuc && j!=kraj)
	{
		if(j<10)
			j++;
		else
			j=0;
	};
	
	if (j!=kraj)
		printf("\n podatak nije pronadjen");
	else
	{
		printf("\n trazeni kluc je: %d",tab[j][0]);
		printf("\n trazeni podatak je: %d",tab[j][1]);
	};
	return;
};

	

void tablica::stampa()
{
	printf("kljuc     podatak \n");
	for(int i=0;i<10;i++)
	{
		printf("%d",tab[i][0]);
		printf("         %d",tab[i][1]);
		printf("\n");
	};
	return;
};

void main()
{
	tablica t;
	int od,k,p;
	printf("\n da li zelite da upisujete u tablicu(1/0):");
	scanf("%d",&od);
	while(od==1)
	{
		printf("\n Unesite kljuc: ");
		scanf("%d",&k);
		printf("\n Unesite podatak: ");
		scanf("%d",&p);
		t.dodavanje(k,p);
		printf("\n da li zelite da upisujete u tablicu(1/0):");
	    scanf("%d",&od);
		
	};
	t.stampa();
	printf("\n da li zelite da trazite? (1/0)");
	scanf("%d",&od);
	while(od==1)
	{
		printf("\n Unesite kljuc: ");
		scanf("%d",&k);
		t.trazenje(k);
		printf("\n da li zelite da trazite (1/0):");
	    scanf("%d",&od);
		
	};

}




