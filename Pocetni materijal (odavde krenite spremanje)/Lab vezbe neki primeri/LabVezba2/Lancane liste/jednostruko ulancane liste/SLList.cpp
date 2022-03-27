#include "SLList.h"
#include <iostream.h>



//pomocu ovog konstruktora kreiramo praznu listu
SLList::SLList()
{
	head=tail=0;
}


//*destruktor obezbedjuje brisanje cele dinamicke liste
SLList::~SLList()
{
	SLLNode *tmp=head;
	while (tmp!=tail)				//*krecemo se od head do tail kroz listu i uvek brisemo
	{								//prvi element u listi
		SLLNode *tmp1=tmp;
		tmp=tmp->link;
		delete tmp1;
	}
	head=tail=0;
}

//*funkcija koja dodaje novi cvor na kraj liste
void SLList::AddToTail(int el)
{
	SLLNode *tmp=new SLLNode(el);		//*ovde u memoriji kreiramo novi cvor za zadatim elementom
	if (head!=0)						//*ukoliko lista nije prazna
	{									//cvor cemo dodati na kraj, tako sto koristimo tail(rep) liste za pristup
										//poslednjem clanu. Znaci, zadnji clan liste treba da nam pokazuje na novododati cvo
	    tail->link=tmp;					//to je upravo ucinjeno ovom komandom
		tail=tail->link;				//ali sad rep treba da nam pokazuje na zadnji cvor. To upravo radi ova komanda
	}
	else
		head=tail=tmp;					//*ukoliko je lista prazna, onda i head i tail moraju da pokazuju na novododati cvor 
}


//*funkcija koja dodaje cvor na pocetak liste
void SLList::AddToHead(int el)
{
	
	SLLNode *tmp=new SLLNode(el);		//*kreiramo novi cvor
	if (head!=0)						//*ukoliko lista nije prazna, link novostvorenog cvora treba da pokazuje
	{									//na cvor na koji je pokazivao head
		tmp->link=head;					//to upravo radi ova komanda

										//link od tmp to znaci ovo ->

		head=tmp;						//a head treba da pokazuje na novododati cvor.To radi ova komanda
	}
	else								//*ukoliko je lista prazna
	{
		tmp->link=0;					//link novog cvora je NULL
		head=tail=tmp;					//a head i tail pokazuju na novi cvor
	}
}

//*funkcija za stampanje liste
void SLList::Print()
{
	SLLNode *tmp=head;					//*za stampanje, treba da prodjemo kroz celu listu i da stampamo info deo 
	while (tmp!=0)						//svakog cvor. To postizemo tako sto krecemo od head, i pomeramo se sve dok
	{									//nam link zadnjeg cvora ne pokazuje na NULL
		cout<<tmp->info<<" ";
		tmp=tmp->link;
	}+ההה
	cout<<endl;
}


//*funkcija koja brise zadnji cvor iz liste
int SLList::DeleteFromTail()
{
	SLLNode *t=tail;			//*napravicemo novi cvor koji pokazuje na cvor na koji pokazuje i tail
	SLLNode *tmp=head;			//*zatim treba da se krecemo kroz listu do cvora (tmp) ciji link pokazuje na sta pokazuje
	while (tmp->link!=tail)		//i tail
		tmp=tmp->link;			//*kad nadjemo taj cvor, tail ce da nam pokazuje na cvor na koji pokazuje i tmp
	int k=tail->info;			//*link pretposlednjeg cvora treba da pokazuje na NULL
	tail=tmp;
	tail->link=0;
	delete t;					//*na kraju ostaje nam samo da obrisemo poslednji cvor
	return k;					//i da vratimo vrednost info dela poslednjeg cvora
}


//*funkcija za brisanje prvog cvora u listi
int SLList::DeleteFromHead()
{
	SLLNode *tmp=head;			//*kreiramo novi cvor koji pokazuje na cvor prvi cvor u listi
	int k=head->info;			
	head=head->link;			//*zatim stavimo da head pokazuje na drugi cvor
	delete tmp;					//*i na kraju brisemo prvi cvor u listi
	return k;					//i vracamo vrednost info dela prvog cvora
}


//*funkcija za brisanje cvora ciji je info deo jednak zadatom delu
void SLList::DeleteElement(int el)
{
	if (head==0)				//*ovde ispitujemo da li je lista prazna
		cout<<"Lista je prazna!!!"<<endl;
	else if (head==tail && head->info==el)	//*ovde ispitujemo da li lista ima samo jedan element
	{										//i ako ima, brisemo ga, a samim tim brisemo i celu listu
		SLLNode *tmp=head;					//odnosno i head i tail su nam 0
		delete tmp;
		head=tail=0;
	}
	else if (head->info==el)				//*ispitujemo da li je info deo prvog elementa jednak zadatom
	{										//i ako jeste, brisemo ga
		SLLNode *tmp=head;					//a head stavljamo da pokazuje na drugi element
		head=head->link;
		delete tmp;
	}
	else									//*ispitivanje kroz listu pocinjemo od drugog elementa
	{
		SLLNode *tmp=head->link;			//*imamo dva pokazivaca koji se krecu kroz listu, jedan koji nam pokazuje na cvor ciji info deo ispitujemo
		SLLNode *tmpp=head;					//i jedan koji nam pokazuje na cvor pre onog ciji info deo ispitujemo
		while (tmp->info!=el && tmp!=tail)	//*kretanje kroz listu zavrsavamo ako pronadjemo cvor ciji je info deo
		{									//jednak elementu ili ako dodjemo do kraja liste
			tmp=tmp->link;
			tmpp=tmpp->link;
		}
	
		if (tmp!=tail)						//*ukoliko smo nasli cvor ciji je info deo jednak elementu
		{			
			SLLNode *tmp1=tmp;
			tmpp->link=tmp->link;			//brisemo taj cvor iz liste
			tmp=tmp->link;					//sta ce onda ovaj cvor tmp1?????????????
			delete tmp1;
		}									//a ukoliko nismo nasli cvor, stampamo poruku
		else
			cout<<"Element se ne nalazi u listi"<<endl;
	}


}


//*funkcija ispituje da li je neki element u listi
void SLList::IsInList(int el)
{
	if (head==0)								//*prvo ispitujemo da li je lista prazna
		cout<<"Lista je prazna!!!"<<endl;		//i ako jeste, stampamo poruku
	else										//*ako lista nije prazna
	{
		SLLNode *tmp=head;						//krecemo se od head do tail kroz listu i ispitujemo da li
		while (tmp->info!=el && tmp!=tail)		//je info deo cvora jednak trazenom elementu
			tmp=tmp->link;						//i ako jeste, stampamo poruku da je element pronadjen
		if (tmp!=tail)							
			cout<<"Element se nalazi u listi"<<endl;
		else
			cout<<"Element se ne nalazi u listi"<<endl;
	}

}


//*funkcija brise sve elemente iz liste
void SLList::DeleteAll()
{
	SLLNode *tmp=head;
	while (tmp!=tail)				//*krecemo se od head do tail kroz listu i uvek brisemo
	{								//prvi element u listi
		SLLNode *tmp1=tmp;
		tmp=tmp->link;
		delete tmp1;
	}
	head=tail=0;					//*na kraju stavimo da i head i tail pokazuju na NULL
}


//*funkcija vraca broj cvorova u listi
int SLList::NumberOfNodes()
{
	int i=0;	
	SLLNode *tmp=head;		//*krecemo se kroz listu do kraja
	while (tmp!=0)			//i brojac uvecavamo za 1
	{
		i++;
		tmp=tmp->link;
	}
	return i;
}

/*void SLList::Sort()
{

		SLLNode *a;
		SLLNode *b;
		SLLNode *c;

		if (head->info>head->link->info)
		{
			a=head->link->link;
			b=head->link;
			c=head;

			head->link->link=c;
			head->link=a;
			head=b;
		}

	

	this->Print();

	SLLNode *k=head;
	
	while (k->link!=tail)
	{
		if (k->info<k->link->info)
		{
			a=k->link->link->link;
			b=k->link->link;
			c=k->link;

			k->link->link->link=c;
			k->link->link=a;
			k->link=b;
		}

		this->Print();

		k=head->link;
	}


	if (head->info>head->link->info)
		{
			a=head->link->link;
			b=head->link;
			c=head;

			head->link->link=c;
			head->link=a;
			head=b;
		}

	

	this->Print();

	k=head;
	
	while (k->link!=tail)
	{
		if (k->info<k->link->info)
		{
			a=k->link->link->link;
			b=k->link->link;
			c=k->link;

			k->link->link->link=c;
			k->link->link=a;
			k->link=b;
		}

		this->Print();

		k=head->link;
	}


}*/