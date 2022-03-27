/****************Elektronski fakultet u Nisu******************

Predmet:				Strukture podataka
Datum:					2. jun 2008.
Autor:					Stevan Cvetkovic
Broj indeksa:			12177
Skolska:				2007/2008. godina

Tema: 					Grafovi
Laboratorijska vezba: 	9
Zadatak: 				3

Tekst zadatka:

Projektovati klasu za rad sa orijentisanim grafom predstavljenim 
listom suseda i implementirati metod za nalazenje cvorova sa 
izlaznim stepenom 0. 

***************************************************************/

#include "GraohAsList.h"
#include "LinkNode.h"
#include <iostream>
using namespace std;

int main()
{
	LinkNode<int,double> pom;
	GraphAsList<int,double> graph;
	bool m;
	
	m = graph.inserNode(1);
	m = graph.inserNode(2);
	m = graph.inserNode(3);
	m = graph.inserNode(4);
	m = graph.inserNode(5);
	m = graph.inserNode(6);
	
	m = graph.insertEdge(1,3);
	m = graph.insertEdge(1,5);
	m = graph.insertEdge(1,6);
	m = graph.insertEdge(3,3);
	m = graph.insertEdge(3,2);
	m = graph.insertEdge(4,1);
	m = graph.insertEdge(4,3);
	m = graph.insertEdge(4,6);
	m = graph.insertEdge(5,6);
	m = graph.insertEdge(5,4);
	m = graph.insertEdge(6,6);

	cout << "Uneto stablo je: " << endl;
	graph.print();
	cout << endl;

	cout << "Cvor koji ima izlaznih stepen 0 je: " << endl;
	graph.find_Null_Output()->Visit();
	cout << endl;
	
	return 0;
}
