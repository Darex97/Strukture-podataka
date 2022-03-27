#include<stdio.h>
#include<math.h>
void main()
{
	double Pi1=3.0;
	double Pi2=Pi1 + sin(Pi1);
	double e=2.71;
	int iteracija=0;
	while ((Pi2-Pi1)>pow(e,-20))
	{
		Pi1=Pi2;
		Pi2=Pi1 + sin(Pi1);
		iteracija++;
	}
	printf("Pi je:%lf ,a broj iteracija je:%d",Pi2,iteracija);
}