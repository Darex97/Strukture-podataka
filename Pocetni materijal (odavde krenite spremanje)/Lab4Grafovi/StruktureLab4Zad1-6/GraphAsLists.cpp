#include"GraphAsLists.h"
#include<iostream>
using namespace std;
#include<queue>
void GraphAsLists::insertNode(int pod)
{
	LinkedNode* newNode = new LinkedNode(pod, NULL, start, 0);//NULL se odnosi na suseda
	//start, koje je ZA SADA NULL, je naredni cvor
	start = newNode;//i sad menjamo start
	nodeNum++;
}

LinkedNode* GraphAsLists::findNode(int pod)
//klasican search u ll
{
	LinkedNode* ptr = start;
	while (ptr != NULL && ptr->node != pod)
		//ptr->node je ekvivalent ptr->info
	{
		ptr = ptr->next;//naredni cvor, ne sused
	}
	return ptr;
}
bool GraphAsLists::insertEdge(int a, int b)
{
	LinkedNode* pa = findNode(a);
	LinkedNode* pb = findNode(b);
	if (pa == NULL || pb == NULL)
		return false;
	Edge* ptr = new Edge(pb, pa->adj);//pb je dest, a pa->adj je link
	if (ptr == NULL) return false;
	pa->adj = ptr;
	return true;
}
bool GraphAsLists::insertEdge(int a, int b,int w)
{
	LinkedNode* pa = findNode(a);
	LinkedNode* pb = findNode(b);
	if (pa == NULL || pb == NULL)
		return false;
	Edge* ptr = new Edge(pb, pa->adj,w);//pb je dest, a pa->adj je link
	if (ptr == NULL) return false;
	pa->adj = ptr;
	return true;
}
Edge* GraphAsLists::findEdge(int a, int b)
{
	LinkedNode* pa = findNode(a);
	LinkedNode* pb = findNode(b);
	if (pa == NULL || pb == NULL)
	{
		return NULL;
	}
	Edge* ptr = pa->adj;
	while (ptr != NULL && ptr->dest != pb)
	{
		ptr = ptr->link;
	}
	return ptr;
}
bool GraphAsLists::deleteEdge(int a, int b)
{
	Edge* pot = findEdge(a, b);//pot kao poteg
	if (pot == NULL) return false;
	LinkedNode* pa = findNode(a);
	if (pot == pa->adj)//ako je ova grana koju brisemo prvi sused
		//imas granicni slucaj, kao kad si brisao head za ll
	{
		pa->adj = pot->link;//prelancavamo tako da preskocimo pot
		delete pot;
		return true;
	}
	Edge* tpot = pa->adj;//tpot izigrava prethodnog
	while (tpot->link != pot)
		tpot = tpot->link;
	tpot->link = pot->link;//prelancavamo tako da preskocimo pot
	delete pot;
	return true;
}
void GraphAsLists::BFS(int a)
{
	queue<LinkedNode*> q;
	int obidjeno = 0;
	Edge* p;
	LinkedNode* pom = start;
	while (pom != NULL)
	{
		pom->status = 1;//svi su spremni
		pom = pom->next;
	}
	pom = findNode(a);
	if (pom == NULL) return;
	q.push(pom);
	pom->status = 2;//smesten u red
		while (!q.empty())
	{
		pom = q.front();//funkcijom front prepisujes prvi element
		//u redu u pomocnu promenljivu pom :D
		q.pop();//a sa pop ga skidas iz reda
		pom->status = 3;//obradjen
		this->visit(pom);
		p = pom->adj;
		while (p != NULL)
		{
			if (p->dest->status == 1)
			{
				p->dest->status = 2;
				q.push(p->dest);
			}
			p = p->link;
		}
	}

}
void GraphAsLists::visit(LinkedNode* a)
{
	cout << a->node << " ";
}
void GraphAsLists::print()
{
	LinkedNode* ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->node << "->";
		Edge* pa = ptr->adj;
		while(pa!=NULL)
		{
			cout << pa->dest->node << "|";
			pa = pa->link;
		}
		cout << "\n";//endl;
		ptr = ptr->next;
	}
}

void GraphAsLists::maxInDeg()
{
	LinkedNode* ptrTrazenog = start;
	LinkedNode* maxPtr = NULL;
	int max = 0;

	while (ptrTrazenog)
	{
		int br = 0;
		LinkedNode* ptr = start;

		while (ptr)
		{
			Edge* e = ptr->adj;//prvi sused
			while (e)
			{
				if (e->dest->node == ptrTrazenog->node)
					br++;
				e = e->link;//setamo se po granama
			}
			ptr = ptr->next;//naredni cvor, jer moramo u svakom cvoru da vidimo da li neka
			//njegova grana vodi do trazenog cvora
		}
		//sve smo obisli jer je ptr=NULL
		if (br > max)
		{
			max = br;
			maxPtr = ptrTrazenog;
		}
		ptrTrazenog = ptrTrazenog->next;
	}
	if (maxPtr)
	{
		cout << "Cvor sa maksimalnim brojem ulaznih cvorova je: " << maxPtr->node << "." << endl;
		cout << "Ulazni stepen je: " << max << "." << endl;
	}
	else
		cout << "Ni jedan cvor nema ulaznih potega." << endl;
}
void GraphAsLists::maxOutDeg()
{
	LinkedNode* ptrTrazenog = start;
	LinkedNode* maxPtr = NULL;
	int max = 0;
		while (ptrTrazenog)
		{
			int br = 0;
			Edge* e = ptrTrazenog->adj;//prvi sused
			while (e)
			{
					br++;
				e = e->link;//setamo se po granama
			}
			if (br > max)
			{
				max = br;
				maxPtr = ptrTrazenog;
			}
			ptrTrazenog = ptrTrazenog->next;//naredni cvor, jer moramo u svakom cvoru da vidimo da li neka
							//njegova grana vodi do trazenog cvora
		}
	
	if (maxPtr)
	{
		cout << "Cvor sa maksimalnim brojem izlaznih cvorova je: " << maxPtr->node << "." << endl;
		cout << "Izlazni stepen je: " << max << "." << endl;
	}
	else
		cout << "Ni jedan cvor nema izlaznih potega." << endl;
}
void GraphAsLists::outZero()
{
	cout << "Cvorovi sa izlaznim stepenom 0 su: ";
	LinkedNode* ptr = start;
	while (ptr)
	{
		if (ptr->adj == NULL)
		{
			cout << ptr->node << " ";
			//ptr = ptr->next;
		}
		ptr = ptr->next;
	}
	cout << endl;
}
void GraphAsLists::inZero()
{
	cout << "Cvorovi sa ulaznim stepenom 0 su: ";
		LinkedNode* ptrTrazenog = start;

		while (ptrTrazenog)
		{
			int br = 0;
			LinkedNode* ptr = start;

			while (ptr)
			{
				Edge* e = ptr->adj;//prvi sused
				while (e)
				{
					if (e->dest->node == ptrTrazenog->node)
						br++;
					e = e->link;//setamo se po granama
				}
				ptr = ptr->next;//naredni cvor, jer moramo u svakom cvoru da vidimo da li neka
								//njegova grana vodi do trazenog cvora
			}
			//sve smo obisli jer je ptr=NULL
			if (br==0)
			{
				cout << ptrTrazenog->node << " ";
			}
			ptrTrazenog = ptrTrazenog->next;
		}
		cout << endl;
	}
bool GraphAsLists::stronglyConnencted()
{
	LinkedNode* pom = start;
	LinkedNode* pom2;

	while (pom != NULL)
	{
		BFS(pom->node);//moras od svakog cvora da krenes obilazak
		cout << endl;
		pom2 = start;
		while (pom2 != NULL)
		{
			if (pom2->status == 1)
				//zato sto bi trebalo svi 
				//da imaju status 3 ako su svi povezani
			{
				cout << "Graf nije jako povezan." << endl;
				return false;
			}
			pom2 = pom2->next;
		}
		pom = pom->next;

	}
	cout << "Graf jeste jako povezan." << endl;
	return true;
}
void GraphAsLists::adjescentMatrix()//cita se 'adzejsent
{
	LinkedNode** niz = new LinkedNode*[nodeNum];
	//niz pokazivaca na cvorove
	LinkedNode* novi = start;
	int i = 0;
	while (novi)
	{
		niz[i] = novi;
		i++;
		novi = novi->next;
		//sve cvorove smo smestili u niz pokazivaca
		//da bismo se lakse kretali kroz taj niz
	}
	int **matSusedstva = new int*[nodeNum];
	for (i = 0; i < this->nodeNum; i++)
		matSusedstva[i] = new int[this->nodeNum];

	novi = start;
	i = 0;
	while (novi)
	{
		for (int j = 0;j < nodeNum;j++)
		{
			if (findEdge(novi->node, niz[j]->node))
				matSusedstva[i][j] = 1;
			else
				matSusedstva[i][j] = 0;
		}
		novi = novi->next;
		i++;
	}
	//stampanje
	cout << "Matrica susedstva:\n";

	for (int i = 0; i < this->nodeNum; i++)
	{

		for (int j = 0; j < this->nodeNum; j++)
			cout << matSusedstva[i][j]<<" ";

		cout << endl;
	}

	cout << endl << endl;
}

void GraphAsLists::getReachable(int idAirport, int time)
{
	cout << "Sa aerodroma " << idAirport << " se moze stici do: ";
	int sabirac = 0, prethodni = -1;
		queue<LinkedNode*> q;
		Edge* p,*pomocnaGrana;
		LinkedNode* pom = start;
		while (pom != NULL)
		{
			pom->status = 1;//svi su spremni
			pom = pom->next;
		}
		pom = findNode(idAirport);
		//pom = pom->adj->dest;
		if (pom == NULL) return;
		q.push(pom);
		pom->status = 2;//smesten u red
		while (!q.empty())
		{
			pom = q.front();//funkcijom front prepisujes prvi element
							//u redu u pomocnu promenljivu pom :D
			q.pop();
			pom->status = 3;
			if (pomocnaGrana = findEdge(prethodni, pom->node))
			{
				sabirac += pomocnaGrana->weight;

				if (sabirac < time)
					this->visit(pom);
			}
			p = pom->adj;
			while (p != NULL)
			{
				if (p->dest->status == 1)
				{
					p->dest->status = 2;
					q.push(p->dest);
				}
				p = p->link;
			}
			prethodni = pom->node;
		}
}