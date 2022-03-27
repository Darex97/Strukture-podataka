#include <stdio.h>
#include <iostream.h>
#include <string.h>

class tablica
{
protected:
	int tab[10][3];
public:
	int m_nCounter;
	tablica();
	void dodavanje(int kljuc, int pod);
	void stampa();
};

tablica::tablica()
{
	for( int i = 0; i < 10; i++ )
		for( int j = 0; j < 3; j++ )
			tab[i][j] = 0;

	m_nCounter = 0;
};

void tablica::dodavanje(int kljuc, int pod)
{
	int ap, as, hh=1;
	ap = kljuc % 10;
	m_nCounter++;
	
	if ( tab[ap][0] == 0 && tab[ap][2] == 0)
	{
		tab[ap][0] = kljuc;
		tab[ap][1] = pod;
		tab[ap][2] = 1;
	}
	else
	{
		as = (ap + 1)%10;
		int br = ap;
		while (tab[as][2] != 0 )
		{
			if( tab[as][0] == kljuc)
			{
				br = as;
				hh = 0;
			}
			as = (as + 1)%10;
		};

		tab[as][0] = kljuc;
		tab[as][1] = pod;

		if(hh == 0)
		{
			tab[as][2] = br;
		}
		else 
		{
			if(tab[ap][0] == kljuc)
			{
				tab[as][2] = ap;
			}
			else 
			{
				tab[as][2] = 1;
			};
		}
	};

	printf("\nUneti kljuc je: %d", kljuc);
	printf("\nPodatak je: %d", pod);
	printf("\n");

	return;

};

void tablica::stampa()
{
	printf("kljuc    podatak     link\n");
    for( int i = 0; i < 10; i++)
	{
		printf("%d       %d             %d\n",tab[i][0], tab[i][1], tab[i][2]);
	};

	return;
};

void main()
{
	tablica t;
	int od, k, stam;
	char a[10][120];

	printf("Da li zelite da upisujete u tablicu(1/0)?: ");
	scanf("%d", &od);
	
	int i = 0, j = 0;
	while ((od == 1)&&(i < 10)) 
	{
		printf("Unesite rec: ");
		scanf("%s", a[j]);

		k = int(a[j][0]) + 1;
		t.dodavanje(k, j);

		printf("Da li zelite da upisujete u tablicu(1/0)?: ");
		scanf("%d", &od);

		i++;
		j++;
	}

	printf("\nDa li zelis da stampas tabelu(1/0)?:");
	scanf("%d", &stam);

	if(stam == 1) 
	{
		if(t.m_nCounter > 0)
		{
			for(int i = 0; i < t.m_nCounter; i++)
				printf("%s\n", a[i]);
			t.stampa();
		}
		else
			printf("\nTablica je prazna!\n");
	}
	else
	{
		if(stam == 0)
		{
			printf("\nCao!");
		}
		else
			printf("\nPogresan unos!");
	}
}





