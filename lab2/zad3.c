#include <stdio.h>
int main()
{
	int a;
	double kurs;
	printf("Podaj ilosc dolarow oraz kurs dolara wzgledem zlotowek:\n");
	scanf("%d %lf",&a,&kurs);
	printf("Ilosc zlotowek: %.2lf zl\n",a*kurs);
	printf("-----------------\n");
	printf("|DOLARY: %8d|\n",a);
	printf("|KURS: %10.2f|\n",kurs);
	printf("|PLN: %11.2f|\n",a*kurs);
	printf("-----------------\n"); 
	return 0;
}
