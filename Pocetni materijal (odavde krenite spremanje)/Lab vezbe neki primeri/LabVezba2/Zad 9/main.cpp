#include "class.h"
 
int main()
{
            node* x;
            x=new node;
            x->key=5;
            CReorgList y;
            y.dodaj_na_pocetak_liste(*x);
            y.stampaj();
            x=new node;
            x->key=7;
            y.dodaj_na_pocetak_liste(*x);
            y.stampaj();
            x=new node;
            x->key=11;
            y.dodaj_na_pocetak_liste(*x);
            y.stampaj();
            x=new node;
            x->key=22;
            y.dodaj_na_kraj_liste(*x);
            y.stampaj();
            y.idi_na_pocetak(5);
            y.stampaj();
            y.zameni_mesta_sa_prethodnim(7);
            y.stampaj();
            system("pause");
            return 0;
}