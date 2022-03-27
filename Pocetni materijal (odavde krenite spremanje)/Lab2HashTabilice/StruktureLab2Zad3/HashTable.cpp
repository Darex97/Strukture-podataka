#include"HashTable.h"

HashTable::HashTable() 
{
	this->count = 0;
	this->length = 0;
	
}
HashTable::HashTable(int l)
{
	count = brojacSinonima=0;
	length = l;
	this->niz = new HashObject[l];
	this->nizSinonima = new HashObject[l*0.2];
}
HashTable::~HashTable() { delete[] niz; }

int HashTable::f(char* s)
{
	int result = 0;
	int a = 7;
	for (int i = 0;s[i] != '\0';i++)
	{
		result = result << a^s[i];
	}
	return result;
}
int HashTable::h(HashObject obj) 
{
	return(f(obj.getKey()) % length);
}
/*int HashTable::g(int p)
{
	for (int i = 0;i < length;i++)
	{
		int pomocnik = (p + i +5) % length;//moduo length ide
		//da bismo omogucili da sve vrednosti budu unutar tablice.
		//Ja sam proizvoljno dodao 5 da bi bilo bolje rasipanje
		//dolazi do problema ukoliko nema petice u smislu da 
		//se reci koje nisu sinonimi tako tumace.
		//Probaj ako ti nije jasno tako sto ces da izbrises peticu,
		//pokreni program, pa vidi. Problem je sa recima for i do.
		if (niz[pomocnik].isFree())
			return pomocnik;
	}
}*/
void HashTable::insert(HashObject obj)
{
	if (count == length)
		throw "The table is full!";
	long probe = h(obj);
	if (niz[probe].free)
	{
		niz[probe] = obj;
	}
	else
		nizSinonima[brojacSinonima++] = obj;
	count++;
}
void HashTable::insertSinonims()
{
	for (int i = 0;i < brojacSinonima;i++)
	{
		int k = h(nizSinonima[i]);//mesto prvog koji nije sinonim
		while (niz[k].next != -1)
			k = niz[k].next;//trazimo da on, ili njegov sinonim, ne ukazuju ni na sta
		//da bismo za poslednji sinonim ulancali novu vrednost

		int t = k;//krecemo od te vrednosti koja ne ukazuje ni na sta i trazimo
		//slobodno mesto
		while (!niz[t].free)
			t = (t + 1) % 10;//od tog mesta trazimo slobodno
		niz[k].next = t;
		niz[t] = nizSinonima[i];
	}
	count++;
}
/*HashObject HashTable::findMatch(char* s) 
{
	//Ne mozemo da pozovemo hes fju jer nismo prosledili objekat
	//ali mozemo ponovo da je napisemo ;)
	int probe = f(s) % length;
	while (probe != -1)//beskonacna petlja
//sigurno ulazi u nju jer nam indeksi polaze od 0
	{
		if (niz[probe].isEqualKey(s))
		{
			return niz[probe];
		}
		else
		{
			probe=g(probe);
		}
	}
	throw "Trazeni element ne postoji.";
}*/
void HashTable::withdraw(char* s) 
{
	if (count == 0)
		throw "Tabela je prazna.";
	int probe = f(s) % length;
	long prev = -1;//Kao fleg cemo da ga koristimo
	while (probe != -1 && !niz[probe].isEqualKey(s))
	{
		prev = probe;
		probe = niz[probe].next;
	}
	if (probe == -1)
		throw "Element nije nadjen.";
	if (prev != -1)//brise se sinonim
	{
		niz[prev].next = niz[probe].next;
		niz[probe].deleteRecord();
		//niz[probe].free = true;
	}
	else
	{
		if (niz[probe].next == -1)
		{
			niz[probe].deleteRecord();
			//niz[probe].free = true;
		}
		else
		{
			long nextEl = niz[probe].next;
			niz[probe].deleteRecord();
			niz[probe] =niz[nextEl];
			niz[probe].next = niz[nextEl].next;
			niz[nextEl] = HashObject();
			niz[nextEl].free = true;
		}
	}
	count--;
}

void HashTable::printAll() 
{
	if (count == 0)
		throw "Hes tablica je prazna.";
	for (int i = 0;i < length;i++) 
	{
		cout << "[" << i << "]" << "->" << " ";
		if (niz[i].getKey() != NULL)
		{
			niz[i].print();
		}
		else
			cout << "Ovo mesto je prazno.";
		cout << endl;
	}
}