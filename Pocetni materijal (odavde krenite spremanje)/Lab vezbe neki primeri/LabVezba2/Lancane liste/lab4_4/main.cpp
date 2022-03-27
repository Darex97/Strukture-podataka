#include "cvor.h"
#include <iostream.h>

cvor* createlist(int n);
void print_list(cvor*);
cvor* createlistp(int n);
cvor* merge_lists(cvor * prva, cvor * druga);
cvor* merge_lists2(cvor*,cvor*);

int main(void)
{
	cvor * list1;
	cvor * list2;
	cvor * list3;
	cout << "================ prva ================="<<endl;
	list1 = createlist(5);
	cout << "================ druga ================"<<endl;
	list2 = createlist(5);
	cout << "======================================="<<endl;

//	list3 = merge_lists(list1, list2);
	list3 = merge_lists2(list1,list2);
	
	cout << "================ lista ================"<<endl;
	cout<<endl;
	print_list(list3);
	cout<<endl;
	return 1;
}

cvor* createlist(int n)
{
	cvor * start_ptr = NULL;
	cvor * temp2;  //pointer na novi cvor koji se zove temp
	for (int i = 0; i < n; i++)
	{
		cvor* temp = new cvor();
		cout << "Unesite vrednost cvora "<<i+1<<":  ";
		cin >> temp->info;

		if (start_ptr == NULL)
			start_ptr = temp;
		else
		{
			temp2 = start_ptr;
			while(temp2->next != NULL)
			{
				temp2 = temp2->next;
			}
			temp2->next = temp;
		}
	}
	return start_ptr;
}

void print_list(cvor* a)
{
	while (a)
	{
		cout << a->info <<"-->";
		a=a->next;
	}
	cout<<"END"<<endl;
}

cvor* createlistp(int n) //pravi lancanu listu inicijalizovanu nulama
{
	cvor * start_ptr = NULL;
	cvor * temp2;		 //pointer na novi cvor koji se zove temp
	for (int i = 0; i < n; i++)
	{
		cvor* temp = new cvor();
		temp->info = 0;
		if (start_ptr == NULL)
			start_ptr = temp;
		else
		{
			temp2 = start_ptr;
			while(temp2->next != NULL)
			{
				temp2 = temp2->next;
			}
			temp2->next = temp;
		}

	}
	
	return start_ptr;
}
//spaja dve sortirane liste
cvor* merge_lists(cvor* prva, cvor* druga)
{
	cvor* temp1 = prva;
	cvor* temp2 = druga;
	cvor* temp3;
	cvor* pom_ptr;
	int i=0,j=0;
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
		i++;
	}
	i++;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
		i++;
	}
	i++;//i je brojac elemenata nove liste

	temp1 = prva;
	temp2 = druga;
	cvor* pomlist;
	
	bool ORE1 = false; //ORE - One Reached the End
	bool ORE2 = false;
	bool prvi = true;
	bool prviore = true;
	bool drugiore = true;

	for(j=0;j<i;j++)
	{
		if((!ORE1) && (!ORE2))
		{
			if (temp1->info <= temp2->info)
			{ //prebacujemo prvi i pomeramo temp1 za 1
				//samo ovde da dodamo preusmerenje elemenata
				if(prvi) 
				{
					pomlist = temp1;
					temp3 = temp1;
					if(temp1->next == NULL) 
						ORE1 = true;
					temp1 = temp1->next; //prelazimo na sledeci element
					pomlist->next = NULL; 
				//  novi element liste je na kraju pa ima vrednost pointera
				//	NULL (moze preko pomlist jer je to prvi element)
					prvi = false;
				}
				else
				{
					pom_ptr = temp1;
					if(temp1->next == NULL) 
						ORE1 = true;
					temp1 = temp1->next;
					temp3->next = pom_ptr;
					temp3 = temp3->next;
					temp3->next = NULL;
				}
							
			}
			else
			{  //prebacujemo iz drugog i pomeramo na sledeci cvor
			
				if (prvi) 
				{
					pomlist = temp2;
					temp3 = temp2;
					if(temp2->next == NULL)	
						ORE2 = true;
					temp2 = temp2->next; //prelazimo na sledeci element
					pomlist->next = NULL; // novi element liste je na kraju pa ima vrednost pointera NULL (moze preko pomlist jer je to prvi element)
				//	temp3 = pomlist; //ukazuje na prvi u listi odnosno ovde poslednji
					prvi = false;
				}
				else
				{
					pom_ptr = temp2;
					if(temp2->next == NULL)	
						ORE2 = true;
					temp2 = temp2->next;
					temp3->next = pom_ptr;
					temp3 = temp3->next;
					temp3->next = NULL;
				}

			}
		}//prvi if uslov
		else
		{
			if (ORE1)  //kad prvi put udje znaci da nije dodao poslednji element iz prve liste
			{
				if(prviore)
				{
					temp3->next = temp1;
					prviore = false;
				}
			    pom_ptr = temp2;
				temp2 = temp2->next;
				temp3->next = pom_ptr;
				temp3 = temp3->next;
				temp3->next = NULL;

			}
			else
			{  //ako je ORE2 //kad prvi put udje znaci da nije dodao poslednji element iz druge liste

				if(drugiore)
				{
					temp3->next = temp2;
				}
				pom_ptr = temp1;
				temp1 = temp1->next;
				temp3->next = pom_ptr;
				temp3 = temp3->next;
				temp3->next = NULL;

			}
		}

		//ako dodje do kraja nekog prekini proveru i samo dodaj na kraj ostatak nezavrsenog niza
	}
return pomlist; //ovo konacno radi
}





// SPAJANJE DVE UREDJENE LISTE
cvor* merge_lists2(cvor *lst1, cvor *lst2)
{
	cvor *lst=NULL;
	cvor *posl=NULL;
	cvor *tek;
	while (lst1 && lst2)
	{
		if (lst1->info < lst2->info)
		{ 
			tek=lst1;
			lst1=lst1->next;
		}
		else
		{
			tek=lst2;
			lst2=lst2->next;
		}
		tek->next=NULL;
		if(lst==NULL)
			lst=tek;
		else
			posl->next=tek;
		posl=tek;
	}	// end while

	if(lst1)
	{
		if(lst==NULL) 
			lst=lst1;
		else
			posl->next=lst1;
	}
	else
	{
		if(!lst)
			lst=lst2;
		else
			posl->next=lst2;
	}

	return lst;
}
