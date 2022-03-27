#include "Cvor.h"
class UrBinStablo
{
public:
	Cvor* root;
	int brEl;
	UrBinStablo()
	{
		root=NULL;
		brEl=0;
	}
	void ubaciCvor(int el)
	{
		if (root==NULL)
			root=new Cvor(el);
		else
		{
			Cvor* p=root;
			Cvor* prethodni=root;
			while(p!=NULL)
			{
				prethodni=p;
				switch(p->uporedi(el))
				{
				case -1:
					p=p->dc;
					break;
				case 1:
					p=p->lc;
					break;
				case 0:
					p=NULL;
					break;
				}
			}
			switch(prethodni->uporedi(el))
			{
			case -1:
				prethodni->dc=new Cvor(el);
				break;
			case 1:
				prethodni->lc=new Cvor(el);
				break;
			case 0:
				cout<<"cvor vec postoji"<<endl;
				break;
			}

			/*if(p->uporedi(el)==-1)
			p=p->lc;
			else if(p->uporedi(*/
		}



	}
	void prodjiStablo(Cvor* root)
	{ 
		if(root!=NULL)
		{
			prodjiStablo(root->lc);
			cout<< " "<<root->info;
			prodjiStablo(root->dc);

		}
	}
	void spojiSa(Cvor* root)
	{
		if(root!=NULL)
		{
			spojiSa(root->lc);
			this->ubaciCvor(root->info);
			spojiSa(root->dc);
		}
	}
	void brisanjeKopiranjem(int el)
	{
		Cvor* node,*p,*prev;
		prev=p=root;
		while(p!=NULL &&  !(p->uporedi(el)==0))
		{
			if((p->uporedi(el)==-1))
				p=p->dc;
			else
				p=p->lc;
		}
		node=p;
		if(p!=NULL && (p->uporedi(el)==0))
		{
			if(node->dc==NULL)
				node=node->lc;
			else 
				if(node->lc==NULL)
					node=node->dc;
				else
				{
					Cvor* tmp=node->lc; //trzimo najdesniji u levom podstablu
					Cvor* pret=node;
					while(tmp->dc!=NULL)
					{
						pret=tmp;
						tmp=tmp->dc;
					}
					node->info=tmp->info;
					if(pret==node)
						pret->lc=tmp->lc;
					else
						pret->dc=tmp->lc;
					delete tmp;
					brEl--;
					return;
				}
				if(p==root)
					root=node;
				else
					if(prev->lc==p)
						prev->lc=node;
					else 
						prev->dc=node;
				delete p;
				brEl--;
		}
		else 
			if(root!=NULL)
				cout<<"\n nije u stablu"<<endl;
			else
				cout<<"stablo je prazno"<<endl;
	}




};
