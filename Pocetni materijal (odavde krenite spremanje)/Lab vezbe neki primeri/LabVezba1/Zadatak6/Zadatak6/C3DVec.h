#pragma once
class C3DVec
{
private:
	double* vektor;
public:
	C3DVec();
	C3DVec(double x,double y,double z);
	double Dot(C3DVec Vektor);
	C3DVec Cross(C3DVec Vektor);
	void stampaj();
	~C3DVec();
};

