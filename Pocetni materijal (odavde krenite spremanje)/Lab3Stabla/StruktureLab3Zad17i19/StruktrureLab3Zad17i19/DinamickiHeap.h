#pragma once
#include"HeapElement.h"
//MISLIM DA TREBA DA OBRATIS PAZNJU NA STABLA KOJA SU PREDSTAVLJENA
//DINAMICKI I HIP KOJI JE URADJEN STATICKI
//ZATO STO TO IMAS DATO NA RACUNSKIM
//Proveri da li ce oni da vas uslovljavaju za tip implementacije. :D
//Srecno! :D
class DinamickiHeap 
{
public:
	HeapElement* koren;
	int brojElemenata;
public:
	DinamickiHeap();
	~DinamickiHeap();
	void obrisiHeap(HeapElement*);
	void ubaci(int);
	void inorderPrikaz();
	void inorderPrikaz(HeapElement*);
	//17. zadatak
	void spojiHipove(DinamickiHeap&);
	void ubaciElemente(HeapElement*);
	//19. zadatak
	void prebaciUMinHeap();
	void prebaciUPolje(int*,HeapElement*);
	void ubaciUMinHeap(int);

	//2016 - ne valja, uradio sam ga preko statickog hipa i okej je
//	void update(int val, int add);//ZA MIN HEAP
	//HeapElement** trazim(int,HeapElement*);
};