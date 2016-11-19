#include <stdio.h>
int main() 
{
	printf("Podaj liczbe:\n");
	int n,a;
	scanf("%d",&n);
	int tab[n],tab2[n];
	printf("Podaj elementy tablicy:\n");
	for (a=0;a<n;a++)
	{
		scanf("%d",&tab[a]);
	}
	printf("Tablica odwrocona:\n");
	for (a=0;a<n;a++)
	{
		tab2[a]=tab[n-1-a];
		printf("%d ",tab2[a]);
	}
	printf("\n");
	return 0;
}
