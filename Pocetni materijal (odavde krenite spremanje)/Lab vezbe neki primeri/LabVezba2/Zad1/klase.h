class Lancana_lista
{
	double koef;
	int exp;
	Lancana_lista* sledeci;
public:
	Lancana_lista();
	Lancana_lista(double k,int m);
	~Lancana_lista();
	void dodaj(double k,int m);
	void povezi(Lancana_lista& p);
	double vrati_vrednost() {return this->koef;}
	int vrati_eksponent(){return this->exp;}
	Lancana_lista* ukazi_na_sledeci(){return sledeci;};
};
class CPolynom
{
	int broj_clanova;
	Lancana_lista* start;
public:
	CPolynom();
	~CPolynom();
	void Coef(int exp,double coef);
	friend CPolynom& Add(CPolynom& poly1,CPolynom& poly2);
	CPolynom& operator=(CPolynom& poly);
	void stampaj();
	double vrati_vrednost(int stepen);
	int vrati_stepen();
	int vrati_broj_clanova(){return this->broj_clanova;}
};