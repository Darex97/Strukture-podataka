#pragma once

class CvorListe {
public:
	int info;
	CvorListe* next;
public:
	CvorListe();
	CvorListe(int a);
	CvorListe(int a, CvorListe* novi);
	~CvorListe();
	void print();
	bool isEqual(int a);
};