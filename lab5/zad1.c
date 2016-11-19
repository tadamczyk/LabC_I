#include <stdio.h>
int main() 
{
	printf("Podaj liczbe:\n");
	int n,a=2;
	scanf("%d",&n);
	int tab[n];
	tab[0]=0;
	tab[1]=1;
	for (;a<=n;a++)
	{
		tab[a]=tab[a-1]+tab[a-2];
	}
	printf("Ciag Fibonacciego n-elemntow+1:\n");
	for (a=0;a<=n;a++)
	{
		printf("%d ",tab[a]);
	}
	printf("\n");
	return 0;
}
