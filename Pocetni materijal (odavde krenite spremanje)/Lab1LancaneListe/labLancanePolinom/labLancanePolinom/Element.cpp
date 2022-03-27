#include "element.h"
void Element::Stampaj()
{
	if (this->koef >= 0)
	{
		cout << "+";
	}
	cout << this->koef << "*x^" << this->stepen;
}