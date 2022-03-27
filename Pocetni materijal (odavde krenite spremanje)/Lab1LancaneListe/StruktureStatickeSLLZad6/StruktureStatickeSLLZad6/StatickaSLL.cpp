#include"StatickaSLL.h"
#include<iostream>
using namespace std;
StatickaSLL::StatickaSLL() 
{
	this->size = 0;
}
StatickaSLL::StatickaSLL(int s) {
	this->size = s;
	info = new int[size];
	next = new int[size];
	for (int i = 2;i < size;i++)
	{
		next[i] = i + 1;
	}
	next[0] = 2;//lrmp
	next[1] = -1;//head
	//ovo -1 posmatraj kao NULL pointer
	next[size - 1] = -1;//poslednji ukazuje na null
}
StatickaSLL::~StatickaSLL() {
	delete[] info;
	delete [] next; 
	//S obzirom da baratamo sa nizovima sada ih moramo
	//izbrisati
}
void StatickaSLL::addToHead(int el)
{
	if (next[0] == -1) 
	{
		cout << "Nema raspolozivog prostora." << endl;
		return;
	}
	int indeksNovog = next[0];
	//indeks gde smestamo element
	//je onaj na koji ukazuje lrmp
	info[indeksNovog] = el;
	//njegov info je prosledjena vrednost
	next[0] = next[indeksNovog];
	//lrmp sada treba da ukazuje na naredno
	//slobodno mesto, tj. na next[indeksNovog]
	next[indeksNovog] = next[1];
	//next[indeksNovog] je onaj na koji ukazuje glava
	//ovim vrsimo ulancavanje
	next[1] = indeksNovog;
	//a glava ukazuje na onaj indeks
	//gde nam je smesten novi element
	//NACRTAJ I IDI KORAK PO KORAK
}
void StatickaSLL::print() {
	for (int i = next[1];i != -1;i=next[i])
	{
		cout << info[i] << " ";
	}
	cout << endl;
	cout << "Next glave: " << next[1] << endl;
	for (int i = next[1];i != -1;i = next[i])
	{
		cout << next[i] << " ";
	}
	cout << endl;
}

//Mislim da nije moguce menjati next delove, tj. da se sortiranje
//vrsi samo zamenom info delova
/*
void StatickaSLL::bubbleSort() {
	int pomocniBubbleBrojac;
	int i, j, m;
	//Ideja:
	/*
	//Prebrojis koliko imas elemenata, za to sluzi prvi for.
	//I svaki put obilazis jedan element manje, jer ce na kraj
	//niza uvek da ti "ispliva" najveci.
	


		int glavniBubbleBrojac=size-1;
		//manje jedan jer jedan ode na lrmp
	

	while (glavniBubbleBrojac != 0)
	{

		pomocniBubbleBrojac = 0;
		j = next[1];

		while (pomocniBubbleBrojac<glavniBubbleBrojac - 1)
			//kao da ides od 0 do n-1
		{
			int flag = 0;
			if (info[j] > info[next[j]])
			{
				//Ako je levi veci od desnog, zamenis im mesta
				int tmpInfo = info[next[j]];
				int tmpNext = next[next[j]];
			int a=	next[next[j]]=next[j];
				int b= info[next[j]] = info[j];
				//a i b samo radi prolaska kroz dibager da vidim nesto
				if (info[j] == info[next[1]])
				{
					//Granicni slucaj ako menjas sa glavom lancane liste.
					//Ovo je granicni slucaj jer glava nema prethodni
					//element koji ukazuje na nju.
					//Sto jeste slucaj sa ostalim elementima.
					info[next[1]] = tmpInfo;
					next[next[1]] = tmpNext;
					next[1] = next[next[j]];
					
			
				}
				else
				{
					//a ovo je slucaj za sve ostale vrednosti
					for (m = next[1];info[next[m]] != info[j];m = next[j]);
					next[m] = tmpNext;

				}
				flag = 1;
			}
			if (flag == 0)
			{
				//ako nista nisi zamenio ipak moras da se pomeris 
				//za jedan element u desno
				j = next[j];
			}
			cout << endl;
			print();
			pomocniBubbleBrojac++;
		}
		glavniBubbleBrojac--;
		//svaki put obilazimo jedan element manje
		//jer je poslednji uvek najveci, tj. vec sortiran
	}
}

*/

void StatickaSLL::bubbleSort(bool rastuci)
{
	for (int i = next[1]; i != -1; i = next[i])
		for (int j = next[i]; j != -1; j = next[j])
		{
			if (rastuci)
			{
				if (info[i]>info[j])
				{
					int tmp = info[i]; // treba da se uradi zamena pokazivaca, a ne vrednosti
					info[i] = info[j];
					info[j] = tmp;
				}
			}
			else if (info[i]<info[j])
			{
				int tmp = info[i];
				info[i] = info[j];
				info[j] = tmp;
			}
		}

}