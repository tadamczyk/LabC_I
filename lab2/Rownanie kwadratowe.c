#include <stdio.h>
#include <math.h>
int main() 
{
	double a,b,c;
	printf("Podaj a, b i c:\n");
	scanf("%lf %lf %lf",&a,&b,&c);
	double d=b*b-4*a*c;
	if (d<0) printf("Brak miejsc zerowych\n");
	if (d==0) printf("x wynosi %.2lf\n", (-1*b)/(2*a));
	if (d>0) printf("x wynosi %.2lf oraz %.2lf\n", (-1*b-sqrt(d))/(2*a), (-1*b+sqrt(d))/(2*a));
	return 0;
}
