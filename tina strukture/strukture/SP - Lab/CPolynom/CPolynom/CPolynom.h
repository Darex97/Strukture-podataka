#pragma once

class CPolynom
{
private:
	int order;
	double* coefs;

public:
	CPolynom();

private:
	void AllocateMemory(int order);

public:
	CPolynom(int order);

private:
	void CopyCoefs(const CPolynom& poly);

public:
	CPolynom(const CPolynom& poly);

private:
	void DeallocateMemory();

public:
	~CPolynom();

	CPolynom& operator=(const CPolynom& poly);

	void Coef(int exp, double coef);

	static CPolynom Add(const CPolynom& poly1, const CPolynom& poly2);
	static CPolynom Mul(const CPolynom& poly1, const CPolynom& poly2);

	void Print();
};