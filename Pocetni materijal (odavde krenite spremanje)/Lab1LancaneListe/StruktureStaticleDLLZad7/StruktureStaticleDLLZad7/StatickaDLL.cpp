#include"StatickaDLL.h"
#include<iostream>
using namespace std;

StatickaDLL::StatickaDLL() { this->size = 0; }
StatickaDLL::StatickaDLL(int s)
{
	this->size = s;
	info = new int[size];
	next = new int[size];
	prev = new int[size];
	prev[0] = prev[1] = -1;//prev lrmp-a i head-a
	next[0] = 2;
	next[1] = -1;//next -II-
	next[size - 1] = -1;//poslednji ukazuje na null
	for (int i = 2;i < size;i++)
	{
		next[i] = i + 1;
		prev[i] = prev[i] - 1;
	}
}
StatickaDLL::~StatickaDLL() 
{
	delete[] info;
	delete[] next;
	delete[] prev;
}
void StatickaDLL::addToHead(int el) {

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

void StatickaDLL::print() {
	for (int i = next[1];i != -1;i = next[i])
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
	for (int i = next[1];i != -1;i = next[i])
	{
		cout << prev[i] << " ";
	}
	cout << endl;
}
void StatickaDLL::bubbleSort(bool rastuci)
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