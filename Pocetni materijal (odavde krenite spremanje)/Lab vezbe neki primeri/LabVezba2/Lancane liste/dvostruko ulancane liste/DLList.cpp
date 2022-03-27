#include "DLList.h"
#include <iostream.h>

//*konstruktor koji kreira praznu listu
DLList::DLList()
{
	head=tail=0;				//*prezna lista je kreirana ako i head i tail pokazuju na NULL
}

DLList::~DLList()
{
}


//*funkcija dodaje cvor na kraj lista
void DLList::AddToTail(int el)
{
	DLLNode *tmp=new DLLNode(el);			//*prvo kreiramo cvor
	if (head!=0)							//*prvo ispitujemo da li je lista prazna i ukoliko nije
	{
		tail->next=tmp;						//stavljamo da next zadnjeg cvora pokazuje na novi
		tmp->prev=tail;						//zatim stavljamo prev dodatog cvora pokazuje na prethodno zadnji cvor
		tail=tmp;							//i na kraju tail treba da pokazuje na novi cvor
	}
	else									//*ukoliko je lista prazna
	{
		head=tail=tmp;						//onda i head i tail treba da pokazuju na novi cvor
	}
}


//*funkcija dodaje cvor na pocetak liste
void DLList::AddToHead(int el)
{
	DLLNode *tmp=new DLLNode(el);			//*prvo kreiramo novi cvor
	if (head!=0)							//*ispistujemo da li je lista prazna
	{	
		tmp->next=head;						//i ukoliko nije next novog cvora treba da pokazuje na cvor na koji je pokazivao head
		head=tmp;							//a head treba da pokazuje na novi cvor
	}
	else									//*ukoliko je lista prazna
		head=tail=tmp;						//i head i tail treba da pokazuju na novi element
}


//*funkcija za stampanje cele liste
void DLList::Print()
{
	for(DLLNode *tmp=head;tmp!=0;tmp=tmp->next)		//*krecemo se kroz listu od head do kraja
		cout<<tmp->info<<" ";						//i stampamo info deo svakog cvora
	cout<<endl;
}


//*funkcija za brisanje zadnjeg cvora iz liste
int DLList::DeleteFromTail()
{
	if (head==0)								//*ukoliko je lista prazna
		cout<<"Lista je prazna!!!"<<endl;		//stampamo poruku
	else if (head==tail)						//*ako lista ima samo jedan element
	{
		int k=head->info;						//u k stavljamo vrednost info dela cvora
		DLLNode *tmp=head;						
		head=tail=0;							//stavljamo da i head i tail pokazuju na NULL sto znaci da praznimo listu
		delete tmp;								//brisemo cvor
		return k;								//i vracamo vrednost info dela izbrisanog cvora
	}
	else
	{											//*ukoliko lista ima vise cvorova
		int k=tail->info;						//u k stavljamo info deo zadnjeg cvora
		DLLNode *tmp=tail;
		tail=tail->prev;						//postavljamo tail da pokazuje na predposlednji element
		tail->next=0;							//i next tog novog poslednjeg elementa treba da pokazuje na NULL
		delete tmp;								//*brisemo cvor
		return k;								//i vracamo info deo izbirsanog cvora
	}
}


//*funkcija brise prvi cvor u listi
int DLList::DeleteFromHead()	
{		
	if (head==0)								//*ukoliko je lista prazna
		cout<<"Lista je prazna!!!"<<endl;		//stampamo poruku
	else if (head==tail)						//*ako lista sadrzi samo jedan element
	{
		int k=head->info;						//u k stavljamo vrednost info dela cvora
		DLLNode *tmp=head;
		head=tail=0;							//stavljamo da i head i tail pokazuju na NULL sto znaci da praznimo listu
		delete tmp;								//brisemo cvor
		return k;								//i vracamo vrednost info dela izbrisanog cvora
	}
	else
	{											//*ako lista ima vise cvorova
		int k=head->info;
		DLLNode *tmp=head;
		head=head->next;						//head treba da pokazuje na drugi cvor u listi
		head->prev=0;							//a prev drugog cvor treba da pokazuje na NULL
		delete tmp;								//brisemo prvi cvor liste
		return k;								//i vracamo info deo njegovog dela
	}
}

//*funkcija brise cvor koji info deo jednak zadatom elementu
void DLList::DeleteElement(int el)
{
	if (head==0)							//*ako je lista prazna
		cout<<"Lista je prazna!!!"<<endl;	//stampamo poruku
	else if (head==tail && head->info==el)	//*ako lista sadrzi samo jedan cvor i ako je on jednak zadatom elementu
	{
		DLLNode *tmp=head;					//brisemo taj cvor
		head=tail=0;						//i stavljamo da i head i tail pokazuju na NULL odnosno
		delete tmp;							//praznimo listu
	}
	else									//*ukoliko lista sadrzi vise cvorova
	{
		DLLNode *tmp=head;
		while ((tmp->info)!=el && tmp!=tail)	//krecemo se kroz listu do ne nadjemo cvor ciji je element jednak zadatom
			tmp=tmp->next;						//ili ne dodjemo do kraja liste
		if (tmp!=tail)							//*ako nadjemo cvor
		{
			DLLNode *tmpp=tmp;			
			tmp->prev->next=tmp->next;			//next cvora koji prethodi nadjenom treba da pokazuje na cvor koji sledi nadjeni
			tmp->next->prev=tmp->prev;			//a prev cvora koji sledi nadjeni cvor treba da pokazuje na cvor koji prethodi
			delete tmpp;						//nadjenom
		}										//*na kraju brisemo cvor
	}
}


//*funkcija ispituje da li se zadati element nalazi u listi
void DLList::IsInList(int el)
{	
	if (head==0)									//*ako je lista prazna 
		cout<<"Lista je prazna!!!"<<endl;			//stampamo poruku
	else
	{
		DLLNode *tmp=head;							//*ukoliko lista nije prazna
		while (tmp->info!=el && tmp!=tail)			//krecemo se kroz nju do ne nadjemo cvor sa info delom koji je jednak zadatom elementu
			tmp=tmp->next;							//ili do ne dodjemo do kraja liste
		if (tmp!=tail)
			cout<<"Element se nalazi u listi"<<endl;
		else
			cout<<"Element se ne nalazi u listi"<<endl;
		
	}
}


//*funkcija brise celu listu
void DLList::DeleteAll()
{
	DLLNode *tmp=head;
	while (tmp!=tail)				//*krecemo se kroz listu od head do tail
	{								//i brisemo svaki cvor
		DLLNode *tmpp=tmp;
		tmp=tmp->next;
		delete tmpp;
	}	
	head=tail=0;					//*na kraju samo stavimo da i head i tail pokazuju na NULL

}


//*funkcija broji cvorove u listi
int DLList::NumberOfNodes()
{
	int i=0;
	DLLNode *tmp=head;				//*krecemo se kroz listu od head do kraja
	while (tmp!=0)					//i brojac uvecavamo za jedan
	{
		i++;
		tmp=tmp->next;
	}
	return i;
}

