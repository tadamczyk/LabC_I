#include <stdio.h>
int main()
{
	int a,b;
	printf("Podaj dwie liczby:\n");
	scanf("%d %d",&a,&b);
	int suma=0;
	while (a>=1)
	{
		if (a%2!=0) suma=suma+b;
		a=a/2;
		b=b*2;
	}
	printf("Wynik mnozenia: %d\n",suma);
	return 0;
}
