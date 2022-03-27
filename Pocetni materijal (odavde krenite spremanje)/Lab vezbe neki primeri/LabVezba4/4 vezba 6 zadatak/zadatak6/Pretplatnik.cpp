#include "Pretplatnik.h"
#include <cstring>

/*Pretplatnik::Pretplatnik(void)
{
	this->ime=NULL;
	this->prezime=NULL;
	this->brtelefona=-1;
}*/
Pretplatnik::Pretplatnik(char *ime, char *prezime, int br)
{
	strcpy(this->ime,ime);
	strcpy(this->prezime,prezime);
	this->brtelefona=br;
}
int Pretplatnik::getBroj()
{
	return this->brtelefona;

}
char* Pretplatnik::getIme()
{
	return this->ime;
}
char* Pretplatnik::getPrezime()
{
	return this->prezime;
}
void Pretplatnik::setBroj(int i)
{
	this->brtelefona=i;
}
void Pretplatnik::setIme(char *v)
{
	strcpy(this->ime,v);
}
void Pretplatnik::setPrezime(char *v)
{
	strcpy(this->prezime,v);
}
Pretplatnik::~Pretplatnik(void)
{
}
