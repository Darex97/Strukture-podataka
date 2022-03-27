#include <iostream.h>
#include <stdio.h>

class SLLista
{
	int Lista[200][2];

public:

	SLLista(int);
	~SLLista(){};
	void Dodaj(int);
	void Izbor();
	void Stampaj();

};

SLLista::SLLista(int n)
{
	Lista[0][1] = 2;
	Lista[1][1] = 0;

	for( int i = 2; i < 199; i++ )
		Lista[i][1] = i + 1;
	Lista[199][1] = 0;
}

void SLLista::Dodaj(int Vrednost)
{
	int Pom;
	if(Lista[1][1] == 0)
	{
		Lista[1][1] = 2;
		Lista[2][0] = Vrednost;
		Lista[2][1] = 0;
		Lista[0][1] = 3;
		return;
	}

	Pom = Lista[1][1];
	while (Lista[Pom][1] != 0)
		Pom = Lista[Pom][1];
	Lista[Pom][1] = Lista[0][1];
	Pom = Lista[0][1];
	Lista[Pom][0] = Vrednost;
	Lista[0][1] = Lista[Pom][1];
	Lista[Pom][1] = 0;
}


void SLLista::Izbor()
{
	int Pom1, Pom2, IMin, Podatak;

	Pom1 = Lista[1][1];

	while (Lista[Lista[Pom1][1]][1] != 0 )
	{
		Pom2 = Lista[Pom1][1];
		IMin = Pom1;
		do{
			if(Lista[IMin][0] > Lista[Pom2][0])
				IMin = Pom2;
			Pom2 = Lista[Pom2][1];
		}

		while(Lista[Pom2][1] != 0);
		Podatak = Lista[Pom1][0];

		Lista[Pom1][0] = Lista[IMin][0];
		Lista[IMin][0] = Podatak;
		Pom1 = Lista[Pom1][1];
	}
}

void SLLista::Stampaj()
{
	int Pom1;

	Pom1 = Lista[1][1];
	if(Pom1 == 0)
		return;

	printf("\n Lista:");

	while(Pom1 != 0)
	{
		printf("%d ",Lista[Pom1][0]);
		Pom1 = Lista[Pom1][1];
	}

	printf("\n");

}

void main(void)
{
	SLLista RadnaL(1);

	for ( int i = 0; i < 10; i++ )
		RadnaL.Dodaj(i%5);
	RadnaL.Stampaj();
	RadnaL.Izbor();
	RadnaL.Stampaj();
}







