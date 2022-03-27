#include "SLList.h"
#include <iostream.h>

SLList::SLList()
{
	head=tail=NULL;
}

SLList::~SLList()
{
}

void SLList::AddToTail(int k)
{
	if (head==0)
		head=tail=new SLLNode(k);
	else
	{
		tail->link=new SLLNode(k);
		tail=tail->link;
	}
}

void SLList::Print()
{
	for (SLLNode *tmp=head;tmp!=0;tmp=tmp->link)
	{
		tmp->Print();
		cout<<" ";
	}
	cout<<endl;
}

void SLList::Sort()
{

	SLLNode *kraj=head->link;	//promenljivu kraj koristimo da bi oznacili dokle treba da se vrsi sortiranje
	SLLNode *kraj1=head;		//najveci element stavljamo na zadnju poziciju i kraj pomeramo za jedan manje, 
	while (kraj!=tail)			//posto taj najveci element na zadnjoj poziciji ne treba opet da uvrstamo u sortiranje
	{
		kraj=kraj->link;		//promenljiva kraj1 nam pomaze da promenljivu kraj smanjimo za jedno mesto manje
		kraj1=kraj1->link;
	}
	
	

	while (kraj!=head)			//sortiranje liste vrsimo dok nam pokazivac kraj ne pokazuje na prvi element
	{
		if (head->info>head->link->info)	//moramo posebno da vrsimo zamenu prva dva elementa ukoliko je potrebno
		{
			SLLNode *a=head->link->link;
			SLLNode *b=head->link;
			SLLNode *c=head;
			
			bool t=false;				//promenljivu t koristimo kao indikator kod zadnjeg kruga sortiranja kada 
										//nam kraj pokazuje na drugi element. Ako se prvi i drugi element zamene u zadnjem krugu
			if (kraj1==head)			//moramo da promenimo i ono na sta pokazuju kraj i kraj1.
				t=true;

			head->link->link=c;			//zamena prvog i drugog elementa
			head->link=a;
			head=b;
		
			if (t==true)
			{
				kraj1=head;				//ukoliko je zadnji krug, menjamo kraj i kraj1
				kraj=head->link;
			}
			
		}

		SLLNode *tmp=head->link->link;
		SLLNode *tmp1=head->link;
		SLLNode *tmp2=head;

		while (tmp1!=kraj)				//svaki put vrsimo sortiranje do promenljive kraj (bubble sort)
		{
			if (tmp1->info>tmp->info)
			{
				bool p=false;			//i promenljiva p nam pomaze ukoliko menjamo cvorove na koje pokazuju kraj i kraj1
	
				if (tmp==kraj)
					p=true;

				SLLNode *pmt=tmp->link;
				SLLNode *pmt1=tmp1->link;
				SLLNode *pmt2=tmp2->link;
	
				tmp2->link=pmt1;	//zamenjujemo cvorove
				tmp->link=pmt2;
				tmp1->link=pmt;

				SLLNode *pom=tmp;	//sada moramo da zamenimo i pokazivace na cvorove da bi ostali u istom redosledu
				tmp=tmp1;
				tmp1=pom;
			
				if (p==true)		
				{
					kraj=tmp;
					kraj1=tmp1;
				}
			
			}
			bool p=false;

			if (tmp1==tail)
				p=true;

			tmp=tmp->link;
			tmp1=tmp1->link;
			tmp2=tmp2->link;

			if (p==true)			//mora da se pazi i na tail pokazivac koji moramo da promenimo
				tail=tmp1;			//ukoliko menjamo zadnja dva cvora, sto se desava samo u prvom krugu
		}
		kraj=kraj1;
		kraj1=head;
		if (kraj!=head)				//if petlja stoji ukoliko nam na kraju promenljiva kraj pokazuje na prvi element
			while (kraj1->link!=kraj)	//da ne bi zbog promenljive kraj1 doslo do pucanja programa
				kraj1=kraj1->link;
	}


}