
#include"BinarniStatickiHip.h"
void main()
{
	/*BinarniStatickiHip heap1(15);
	BinarniStatickiHip* heap2 = new BinarniStatickiHip(10);

	heap1.ubaci(12);
	heap1.ubaci(28);
	heap1.ubaci(32);
	heap1.ubaci(45);
	heap1.ubaci(22);
    cout << "Prvi hip: ";
	heap1.stampaj();

	heap2->ubaci(3);
	heap2->ubaci(1);
	heap2->ubaci(22);
	heap2->ubaci(5);


	cout << "Drugi hip: ";
	heap2->stampaj();

	cout << "Spojeni hipovi: ";
	heap1.spojiHipove(*heap2);
	heap1.stampaj();
	delete heap2;

	cout << "Nakon minhip konverzije:";
	heap1.prebaciUMinHip();
	heap1.stampaj();*/

	BinarniStatickiHip h1(10);
	h1.ubaciUMin(2);
	h1.ubaciUMin(7);
	h1.ubaciUMin(9);
	h1.ubaciUMin(10);
	h1.ubaciUMin(15);
	h1.ubaciUMin(32);
	h1.ubaciUMin(45);
	h1.stampaj();
	//h1.update(7, 4);
	h1.update(7, -6);
	h1.stampaj();

}
