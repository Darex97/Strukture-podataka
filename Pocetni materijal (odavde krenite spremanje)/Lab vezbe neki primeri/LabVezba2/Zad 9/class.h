#include <iostream>
using namespace std;
 
struct node
{
            int key;
            node* sledeci;
            node()                                      //konstruktor za strukturu
            {
                        key=0;
                        sledeci=NULL;
            }
};
 
class CReorgList
{
            node* start;
public:
            CReorgList()
            {
                        start=new node;
                        start->key=0;
                        start->sledeci=NULL;
            }
            ~CReorgList()
            {
                        node* pom=start;
                        node* pom1;
                        while(pom!=NULL)
                        {
                                    pom1=pom;
                                    pom=pom->sledeci;
                                    delete pom1;
                        }
            }
            void dodaj_na_pocetak_liste(node& n)
            {
                        node* p;
                        p=start->sledeci;
                        start->sledeci=&n;
                        n.sledeci=p;
            }
            void dodaj_na_kraj_liste(node& n)
            {
                        node* pom=start;
                        while(pom->sledeci!=NULL)
                        {
                                    pom=pom->sledeci;
                        }
                        pom->sledeci=&n;
            }
            node* idi_na_pocetak(int k)
            {
                        node* x=start->sledeci;
                        node* y=x;
                        while(x!=NULL&&x->key!=k)
                        {
                                    y=x;
                                    x=x->sledeci;
                        }
                                    if(x!=NULL)
                                    {
                                                if(x->key==k)
                                                {
                                                            node* pom=start->sledeci;
                                                            start->sledeci=x;
                                                            y->sledeci=x->sledeci;
                                                            x->sledeci=pom;
                                                }
                                    }
                                    return x;
            }
            node* zameni_mesta_sa_prethodnim(int k)
            {
                        node* x=start->sledeci;
                        node* y=start;
                        node* z;
                        while(x!=NULL&&x->key!=k)
                        {
                                    z=y;
                                    y=y->sledeci;
                                    x=x->sledeci;
                        }
                                    if(x!=NULL)
                                    {
                                                if(x->key==k)
                                                {
                                                            z->sledeci=x;
                                                            y->sledeci=x->sledeci;
                                                            x->sledeci=y;
                                                }
                                    }
                        return x;
            }
 
            void stampaj()
            {
                        node* k=start->sledeci;
                        while(k!=NULL)
                        {
                                    cout<<k->key<<" ";
                                    k=k->sledeci;
                        }
                        cout<<endl;
            }
};