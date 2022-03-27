#pragma once

class Pretplatnik
{

protected:
	char ime[30];
	char prezime[30];
	int brtelefona;
public:
	//Pretplatnik(void);
	Pretplatnik (char* ime, char* prezime, int br);
	char* getIme();
	char* getPrezime();
	int getBroj();
	void setIme(char* v);
	void setPrezime(char* v);
	void setBroj(int i);
	virtual ~Pretplatnik(void);
};
