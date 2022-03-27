#pragma once
#include<iostream>
using namespace std;
class StatickoStablo
{
private:
	int** cvorovi;
	int m;//maksimalni broj cvorova
	int t;//trenutni broj cvorova
public:
	StatickoStablo(int);
	~StatickoStablo();
	void ubaci(int);
	void prikazi();
	void prikazi(int);

	int visina();//4. zadatak
	int visina(int);
	int max(int, int);
	int moment();//6. zadatak
	int tezina();//8. zadatak
	void brisanjeListova();//10.zadatak
	void mirrorKopija();//12.zadatak
	void spajanjeStabala(StatickoStablo&);//14. zadatak
	int nivoSaNajviseCvorova();//16.zadatak
};