#include <math.h>
#include "CvorStabla.h"
class BinStablo
{
public:
	int brelemenata;
	CvorStabla* koren;
	BinStablo()
	{
		brelemenata=0;
		koren=NULL;
	}
	~BinStablo()
	{
		obrisiPodstablo(koren);
	}
	void obrisiPodstablo( CvorStabla* korenPodstabla)
	{
		if(korenPodstabla!=NULL){
			obrisiPodstablo(korenPodstabla->levodete);
			obrisiPodstablo(korenPodstabla->desnodete);
			delete korenPodstabla;
		}
	}
	void obrisiCvor(CvorStabla* cvor)
	{
		delete cvor;
	}
	void prodjiStablo(CvorStabla* root)
	{ 
		if(root!=NULL)
		{
			prodjiStablo(root->levodete);
			prodjiStablo(root->desnodete);
			root->obradi();
		}
	}

	int  odrediVisinu(CvorStabla* root,int v,int *a)
	{
		int p1,p2;
		p1=p2=v;
		if (p1>*a)
			*a=p1;
		if (p2>*a)
			*a=p2;
		if(root!=NULL)
		{
			p1=odrediVisinu(root->levodete,p1+1,a);
			p2=odrediVisinu(root->desnodete,p2+1,a);
		}
		return *a;
	}
	int prebrojCvorove(CvorStabla* root,int* a)
	{

		if(root!=NULL)
		{
			prebrojCvorove (root->levodete,a);
			prebrojCvorove (root->desnodete,a);
			(*a)++;
		}
		return *a;
	}


	void ubaciCvor(int pod)
	{
		CvorStabla* pom=new CvorStabla(pod);
		if (koren==NULL)
			koren=pom;
		else 
		{
			CvorStabla* pom1=koren;
			CvorStabla* pom2=koren;
			while(pom1->levodete!=NULL && pom2->desnodete!=NULL)
			{
				pom2=pom2->desnodete;
				pom1=pom1->levodete;
			}
			if(pom1->levodete==NULL)
				pom1->levodete=pom;
			else 
				pom2->desnodete=pom;
		}
		brelemenata++;
	}
	void obrisiListove(CvorStabla* root,CvorStabla* pret)
	{
		if(root!=NULL)
		{
			if(root->levodete==NULL && root->desnodete==NULL)
			{
				if(pret->desnodete==root)
					pret->desnodete=NULL;
				if(pret->levodete==root)
					pret->levodete=NULL;
				cout<<" "<<root->info;

				//delete root;
			}
			obrisiListove(root->levodete,root);
			obrisiListove(root->desnodete,root);
		}


	}
	void dinUStat(CvorStabla* root,int ind,int* niz)
	{
		if(root!=NULL)
		{
		niz[ind]=root->info;
		dinUStat(root->levodete,ind*2,niz);
		dinUStat(root->desnodete,ind*2+1,niz);
		}
	}


};
