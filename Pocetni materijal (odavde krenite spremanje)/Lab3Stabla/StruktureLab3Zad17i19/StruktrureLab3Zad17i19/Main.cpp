#include"DinamickiHeap.h"

void main()
{
	DinamickiHeap dh1;
	DinamickiHeap* dh2 = new DinamickiHeap();

	dh1.ubaci(12);
	dh1.ubaci(28);
	dh1.ubaci(32);
	dh1.ubaci(5);
	dh1.ubaci(45);
	dh1.ubaci(25);
	dh1.ubaci(15);
	dh1.ubaci(1);
	dh1.ubaci(3);
	dh1.ubaci(4);
	dh1.ubaci(6);
	dh1.ubaci(9);
	cout << "Inorder prvog hipa: ";
	dh1.inorderPrikaz();

	dh2->ubaci(35);
	dh2->ubaci(14);
	dh2->ubaci(17);
	dh2->ubaci(50);

	cout << "Inorder drugog hipa: ";
	dh2->inorderPrikaz();

	dh1.spojiHipove(*dh2);
	delete dh2;

	cout << "Inorder spojenih hipova: ";
	dh1.inorderPrikaz();

	cout << "Inorder MinHip konverzije: ";
	dh1.prebaciUMinHeap();
	dh1.inorderPrikaz();*/
	DinamickiHeap dh1;
	dh1.ubaciUMinHeap(2);
	dh1.ubaciUMinHeap(7);
	dh1.ubaciUMinHeap(9);
	dh1.ubaciUMinHeap(10);
	dh1.ubaciUMinHeap(15);
	dh1.ubaciUMinHeap(32);
	dh1.ubaciUMinHeap(45);

	//HeapElement** tester = dh1.trazim(9, dh1.koren);
	//cout << (*tester)->info << " " << endl;
	//dh1.inorderPrikaz();
}