#include"DinamicBSTree.h"

//Sve zivo cemo da radimo rekruzivno, sto je super
//malo da ukapiras i taj nacin razmisljanja. Nista se
//ne brini, sve je lagano. Samo polako. :D


//Koraci za pisanje rekurzije:                          ||               "Find your way home."
    //1. Osnovni slucaj (uslov za izlazak)              ||              1. Ako si kuci, prestani da se kreces.
    //2. Korak ka osnovnom slucaju                      ||              2. Napravi korak ka kuci.
    //3. Rekurzivni poziv                               ||              3."Find your way home".

DinamicBSTree::DinamicBSTree() { root = NULL; }
DinamicBSTree::~DinamicBSTree() { deleteTree(root); }
void DinamicBSTree::deleteTree(BSTNode* p)
{
	//Sta se desava ovde:
	//Spustas se do listova, a onda brises uvek levi list
	//pa desni, pa se vracas na gore i sve tako redom
	//pa ti je onda taj roditelj p->left brises njega
	//pa desni, pa njihovog roditelja i sve tako.
	if (p != NULL)
		//ovo p!=NULL mozes da posmatras i kao:
		//if (p==NULL) return; tj. da ti ovo bude
		//izlazak iz rekurzije

		//SAVET:
		//Bolja je praksa da pises p!=NULL umesto p==return
		//zato sto nece povratni tip fje uvek da ti bude void
		//a ako je neki povratni tip, na primer, int moraces
		//tu nesto da vratis
	{
		deleteTree(p->left);
		deleteTree(p->right);
		delete p;
	}
}
void DinamicBSTree::insert(int el)
{
	BSTNode* current = root;
	BSTNode* previous = NULL;
	while (current != NULL)
	{
		previous = current;//kao i za LL
		//vodis dva pokazivaca da bi mogo lepo da 
		//umeces
		
		if (current->key > el)
			current = current->left;
		//kreces se suprotno od 
		//smera na koji ti ukazuje relacioni operator
		//sto je i logicno zato sto radis sa uredjenim binarnim stablom
		//koje podrazumeva da je levo dete manje od roditelja, a
		//roditelj manji od desnog deteta
		else if (current->key < el)
			current = current->right;
		else return;//obrati paznju, ako element koji se dodaje
		//vec postoji u stablu, nece biti dodat
	}
	if (root == NULL)//NE ZABORAVI GRANICNI SLUCAJ
		root = new BSTNode(el);//prazno stablo pa prvi element 
	//koji dodajemo je ujedno i koren stabla
	else if (previous->key > el)
		previous->left = new BSTNode(el);
	else if (previous->key < el)
		previous->right = new BSTNode(el);
}
void DinamicBSTree::visit()
{
	visit(root);
	cout << endl;
}
void DinamicBSTree::visit(BSTNode* p)
{
	//inorder
	if (p != NULL)
	{
		visit(p->left);
		cout << p->key << " ";
		visit(p->right);
	}
}

int DinamicBSTree::height() 
{
	return height(root);
}
int DinamicBSTree::height(BSTNode* p)
{
	if (p == NULL)
		return 0;//prazno stablo
	if (p->left == NULL && p->right == NULL)//dosli smo do lista
		return 1;
	return 1 + max(height(p->left), height(p->right));
2//svaki put kad se spustis za nivo od korena dodajes 1
// a kad dodjes do lista takodje samo vratis jedinicu
//pa ti je visina "put" od korena do najdaljeg lista
	//Prati sliku koju imas za ovo stablo:
//Sta se desava u VisualStudio-u:
	//On uvek prvo proverava visinu za desnu stranu i u tvom konkretnom stablu to
	//znaci da se spusta do 10ke, vidi da tu nema dece i vraca 1, pa proverava
	//levu stranu 9ke, vidi da nema nista i vraca 0, uporedjuje ta 2 i vraca veci
	//na sta dodaje jedan. Svaki put nakon poredjenja dodaje jedan!
	//i penje se na gore, sad je zavrsio sa desnom granom 6ice i proverava levu
	//vidi da je tu petica koja nema dece i vraca 1, tu visinu poredi sa
	//sa desnom stranom koja je =2 i vraca veci, tj. 2, i na to dodaje jedan
	//i sad je doso do korena, trojke, ima izracunatu visinu za desnu stranu, pa 
	//krece levo, tu nailazi na jedinicu i ponovo proverava njenu desnu stranu, 
	//vidi da 2 nema dece vraca 1 i to poredi sa levom stranom i na veci
	//od 2 broja dodaje 1 i izracunao je visinu leve strane.
	//Krajnje poredjenje: poredi levo i desno podstablo i odredjuje koje je 
	//vece i dodaje mu po poslednji put jedan.
	//Mislimo da uvek ide sa desne strane zbog steka, jer ce da stavi na stek
	//prvo drugi operand, pa prvi i tako ce da pri pozivu lepo da pozove
	//u redosledu kojim i treba da pozove, prvi pa drugi operand.
}
int DinamicBSTree::max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}
int DinamicBSTree::momentOfTree()
{
	//moment stabla je jednak broju cvorova u stablu
	return momentOfTree(root);
}
int DinamicBSTree::momentOfTree(BSTNode* p)
{
	if (p == NULL)
		return 0;
	if (p->left == NULL && p->right == NULL)
		return 1;//kad dodjes do lista to je jedan cvor
	//i vracas se nazad
	//recimo da imas ovakvo stablo:
	//             *
	//           *   *
	//E, sad: ovaj tvoj donji return vraca ti moment levog podstabla
	//tu ide +1 i isto za desno podstablo +1
	//a ovaj 1 na pocetku return-a je za njihvog roditelja

	//Tj. kad god napravis korak dodas 1. I plus dodajes 1
	//kad dodjes do lista, to je sve.:D
	return 1 + momentOfTree(p->left) + momentOfTree(p->right);
	//kreces od korena i moras da prebrojis sve i u levom
	//i u desnom podstablu
}
/* MOJE BOLJE alternativno resenje:
Prosto obidjemo stablo, kao i za stamapanje:
int DinamicBSTree::momentOfTree(BSTNode* p)
{
	static int brojac = 0;//mora staticki da ne bi svaki
	//put kad se pozove fja bio na nuli
	if (p == NULL) return 0;
	momentOfTree(p->left);
	brojac++;
	momentOfTree(p -> right);
	return brojac;
}*/
int DinamicBSTree::tezina()
//tezina predstavlja broj listova
{
	return tezina(root);
}
int DinamicBSTree::tezina(BSTNode* p)
{
	if (p == NULL)
		return 0;
	if (p->left == NULL && p->right == NULL)
		return 1;
	return tezina(p->left) + tezina(p->right);
}
void DinamicBSTree::brisanjeListova()
{
	if (root != NULL)
		//Uslov za izlazak:if(root==NULL) return;
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
	}
	brisanjeListova(root);
}
void DinamicBSTree::brisanjeListova(BSTNode* p)
{
	if (p == NULL)
		return;
	if (p->left != NULL)//ovi uslovi su neophodni zbog rekurzivnog poziva
		//funkcije, zato sto ako ovog nema, tj. p->left jeste jednako NULL
		//prosledices kao parametar NULL
	{
		//Ovako proveravamo da li je p list
		if (p->left->left == NULL && p->left->right == NULL)
		{
			delete p->left;//oslobadjamo memoriju
			p->left = NULL;//oslobadjamo pointer,zbog kasnijeg poziva funkcije
		}
	}
	//analogno za p->right
	if (p->right != NULL)
	{
		if (p->right->left == NULL && p->right->right == NULL)
		{
			delete p->right;
			p->right = NULL;

		}
	}
	brisanjeListova(p->left);
	brisanjeListova(p->right);
}
void DinamicBSTree::mirror()
{
	mirror(root);
}
void DinamicBSTree::mirror(BSTNode* p)
{
	//Ides od korena ka listovima!!!

	//Samo konstantno menjas mesta deci dok
	//ne dodjes u situaciju da ti je pokazivac 
	//jednak NULL
	if (p == NULL)
		return;
	//Kako ovo funkcionise:
	//kad zamenis mesta dvama elementima
	//tada menjas mesta i celim podstablima!!! Jer
	//ti elementi "omnia mea mecum porto", sve svoje sa
	//sobom nose. :D
	BSTNode* pom = p->left;
	p->left = p->right;
	p->right = pom;
	mirror(p->left);
	mirror(p->right);
}
void DinamicBSTree::spajamStabla(DinamicBSTree& d)
{
	spajamStabla(d.root);
}
void DinamicBSTree::spajamStabla(BSTNode* p)
{
	//uslov za izlazak iz rekurzije
	if (p == NULL)
		return;
	//ides do krajnjeg levog lista i ubacujes ga
	spajamStabla(p->left);//Uvek fju koju pravis 
	//koristi da se setas po stablu
	//Dokle ces da se setas odredjujes uslovom s pocetka
	this->insert(p->key);
	spajamStabla(p->right);
	//zatim se vracas i ubacujes i desne elemente 
	//ukljucujuci i njihovu decu(levu i desnu)
}
int DinamicBSTree::najviseCvorova()
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return 0;
	int v = height();
	int* zaSvakiNivo = new int[v];
	for (int i = 0;i < v;i++)
		zaSvakiNivo[i] = 0;
	najviseCvorova(zaSvakiNivo, root);
	//rezultat ce se nalaziti u nizu zaSvakiNiz
	//zatim prolazimo kroz niz i trazimo maksimum
	//sto je povratna vrednost funkcije :)
	int imax = 0;
	for (int i = 1;i < v;i++)
	{
		if (zaSvakiNivo[imax] < zaSvakiNivo[i])
			imax = i;
	}
	delete[] zaSvakiNivo;
	//CIM IMAS OPERATOR NEW MORA I OPERATOR DELETE!!!
	return imax;

}
void DinamicBSTree::najviseCvorova(int* zaSvakiNivo, BSTNode* p)
//Ideja: prolazimo kroz stablo i za svaki element u stablu proveravamo na kojoj
//je dubini. Zatim, cuvamo niz dubina zaSvakiNivo i kad god vidimo da neki
//element pripada odgovarajucoj dubini inkrementiramo vrednost 
//odgovarajuceg elementa u nizu koji predstavlja tu dubinu
{
	if (p != NULL)
	{
		najviseCvorova(zaSvakiNivo, p->left);
		zaSvakiNivo[dubinaCvora(p)]++;
		najviseCvorova(zaSvakiNivo, p->right);
	}
}
int DinamicBSTree::dubinaCvora(BSTNode* p)
//dubina je put od korena do konkretnog cvora
{
	if (p == root)
		return 0;//koren je na nivou 0
	return 1 + dubinaCvora(roditeljCvora(p, root));
	//brojeci cvorove od naseg konkretnog cvora do korena, dobijamo
	//dubinu koju trazimo
}
BSTNode* DinamicBSTree::roditeljCvora(BSTNode* d, BSTNode* r)
{
	//Smatram da je ovo mnogo prirodnije resenje od 
	//ovog koje imas ispod iskomentarisano
	//Prosto je nepotrebno zakomplikovano.
	//Ovo je jako slicno insertu.
	BSTNode* previous = NULL;
	BSTNode* current = r;
	if (current->left == NULL && current->right == NULL)
		return NULL;//koren nema roditelja		
	while (d->key != current->key)
	{
		previous = current;

		if (d->key > current->key)
			current = current->right;
		//SAMO PAZI SAD NE IDEMO KONTRA,NEGO KAKO POKAZUJE STRELICA
		//ZATO STO TRAZIMO, NE UMECEMO
		else if (d->key < current->key)
			current = current->left;

	}
	return previous;
}


/*//ovom funkcijom cemo vratiti roditelja cvora
{
	//p je cvor koji prosledjujemo
	//q je koren
	// da li je root NULL
	if (q == NULL)
		return NULL;

	//da li mu je dete, mozda, cvor kome odredjujemo dubinu
	if (q->left == p || q->right == p)
		return q;
	BSTNode* pom;
	pom = roditeljCvora(p, q->left);
	if (pom != NULL)
		return pom;
	pom = roditeljCvora(p, q->right);
	if (pom != NULL)
		return pom;
	return NULL;
}*/

int DinamicBSTree::getDeepest()
{
	BSTNode** deepest = new BSTNode*();
	int a=getDeepest(root, deepest);
	cout << "Nivo sa najdubljim listom: " <<a<< endl;
	cout << "'Deepest' je cvor sa vrednoscu: " << (*deepest)->key << "." << endl;
	
	delete deepest;
	return a;
	
}
int DinamicBSTree::getDeepest(BSTNode* Node, BSTNode** deepest)
{
	BSTNode* p = Node;
	if (p != NULL)
	{
		static int a = -1;
		if (p->left == NULL && p->right == NULL)
		{
			int b = dubinaCvora(p);
			if (a < b)
			{
				a = b;
			   *deepest = p;//Posto si pristupio poointeru pomocu * ispada da si pointeru dodelio pointer
			   //Ovde je nastao mali problem. Radis sa dvostrukim pointerom, pazi sad:
			   //Posto hocemo nesto da upisemo u odredjenu memorijsku lokaciju
			   //a da se to pritom ne izgubi iz fje, moracemo da upisemo na njegovoj adresi
			   //adresi pristupamo koristeci operator *
			   //zato smo iskoristili ovaj zapis
			   //mogli smo i ovako: deepest=&p, to bi takodje proslo
			   //zato sto bismo uzeli adresu pointera i dodelili je pointeru na pointer
			   //ali je problem ovde sto bi se ta vrenost izubila cim bi se izaslo iz fje
			   //u kojoj je ona zapisana

			   //Iz Ciriceve knjige, str. 274:
			   /*int f(int* a)
			   {
				   int pom;
				   pom = *a + 1;
				   *a = *a - 1;
				   return pom;
			   }
			   void main()
			   {
				   int x, y;
				   x = 5;
				   y = f(&x);
				   printf("%d %d", x,y)
			   }
			   Da je x=5;
			   nakon ovog bi bilo pom=6; x=4;
			   ZNACI ZVEZDICU KORISTIS DA BI PROMENIO TO STO JE PROSLEDJENOJ ADRESI
			   */
			   //S obzirom da je u pokazivacu deepest adresa, kada se radi sa dereferenciranim
			   //pokazivacem *deepest u fji se zapravo radi sa stvarnom vrednosu u memorijskom
			   //prostoru glavnog programa
			}
		}
		getDeepest(p->left, deepest);
		getDeepest(p->right, deepest);
		return a;
	}
}
int DinamicBSTree::CountGreater(int value)
{
	return CountGreater(root, value);
}
int DinamicBSTree::CountGreater(BSTNode* p,int v)
{
	/*REKURZIVNO:
	BSTNode* p = b;
	
	if (p == NULL) return 0;
	if (p->key > value)
		return	1+CountGreater(p->left, value) + CountGreater(p->right, value);
	return CountGreater(p->left, value) + CountGreater(p->right, value);*/
	static int brojac = 0;
	if (p != NULL) 
	{
		CountGreater(p->left, v);
		if (p->key > v)
			brojac++;
		CountGreater(p->right, v);
		return brojac;
	}
}
int DinamicBSTree::deleteRightLeaves()
{
	return deleteRightLeaves(root);
}
int DinamicBSTree::deleteRightLeaves(BSTNode* p)
{
	//REKURZIVNO:
	/*	if (p == NULL) return 0;
	if (p->right != NULL)
	{
		if (p->right->left == NULL && p->right->right == NULL)
		{
			//BSTNode*prev = p;
			delete p->right;
			p->right = NULL;
			return 1 + deleteRightLeaves(p->left) + deleteRightLeaves(p->right);
		}
	}
	return  deleteRightLeaves(p->left) + deleteRightLeaves(p->right);*/
	static int brojac=0;
	
	if (p != NULL)
	{
		//if (p->left != NULL)
		//{
			//if (p->left->left == NULL && p->left->right == NULL)
		//	{
			//	delete p->left;
			//	p->left = NULL;
			//}
	//	}
		//analogno za p->right

		//Namerno sam ostavio brisanje levih listova iskomentarisano da uocis slicnost
		//Naime, isto je kao i tipicno brisanje listova, samo sto sada brises samo desne
		if (p->right != NULL)
		{
			if (p->right->left == NULL && p->right->right == NULL)
			{
				delete p->right;
				p->right = NULL;
				brojac++;
			}
		}
		deleteRightLeaves(p->left);
		deleteRightLeaves(p->right);
	}
	return brojac;
}
BSTNode* DinamicBSTree::findMaximal()
{
	return findMaximal(root);
}
BSTNode* DinamicBSTree::findMaximal(BSTNode* p)
{
	int s = razlikaSuma(root);
	BSTNode *povratni = root;
	nadjiCvor(&s, povratni, root);
	return povratni;
}
void DinamicBSTree::nadjiCvor(int* s, BSTNode* povratni, BSTNode* r)
{
	//u povratnom pisemo vrednost
	//r proveravamo
	if (r == NULL) return;
	if (razlikaSuma(r) > *s)
	{
		povratni = r;
		*s = razlikaSuma(r);
	}
	if (r->left == NULL && r->right == NULL) return;
	if (r->left != NULL)
		return nadjiCvor(s, povratni, r->left);
	else if (r->right != NULL)
		return nadjiCvor(s, povratni, r->right);
}
int DinamicBSTree::levaSuma()
{
	return levaSuma(root);
}
int DinamicBSTree::levaSuma(BSTNode* r)
{

	if (r == NULL) return 0;
	if (r->left != NULL)
	{
		BSTNode* p = r->left;
		return p->key + levaSuma(p) + desnaSuma(p);
	}
	else return 0;
}

int DinamicBSTree::desnaSuma()
{
	return desnaSuma(root);
}

int DinamicBSTree::desnaSuma(BSTNode* r)
{

	if (r == NULL) return 0;
	if (r->right != NULL)
	{
		BSTNode* p = r->right;
		return p->key + levaSuma(p) + desnaSuma(p);
	}
	else return 0;
}
int DinamicBSTree::suma(BSTNode *p)
{
	//SUMA CELOG PODSTABLA
	if (p == NULL) return 0;
	return p->key + suma(p->left) + suma(p->right);
}
int DinamicBSTree::razlikaSuma()
{
	return razlikaSuma(root);
}
int DinamicBSTree::razlikaSuma(BSTNode* p)
{
	return abs(levaSuma(p) - desnaSuma(p));
	//moglo je i samo preko fje suma(p->left)- suma(p->right);
}