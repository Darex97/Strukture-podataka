#include<iostream>
using namespace std;

class BinarniStatickiHip
{
private:
	int* elementi;
	int duzina;
	int brojElemenata; 
public:
	BinarniStatickiHip(int);
	BinarniStatickiHip(BinarniStatickiHip&);
	~BinarniStatickiHip();

	void ubaci(int);
	void stampaj();
	//18. zadatak
	void spojiHipove(BinarniStatickiHip&);
	//20.zadatak
	void prebaciUMinHip();
	void ubaciUMin(int);

	//2016 - dobar, care :)
	void update(int val, int add);
	int trazim(int);

};