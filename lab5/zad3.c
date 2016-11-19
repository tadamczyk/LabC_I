#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() 
{
	srand(time(NULL));
	printf("Podaj liczbe elementow tablicy oraz x:\n");
	int n,x,a,i=-1;
	scanf("%d %d",&n,&x);
	int tab[n];
	for (a=0;a<n;a++)
	{
		tab[a]=rand()%100;
		printf("%d\n",tab[a]);
	}
	for (a=0;a<n;a++)
	{
		if (tab[a]==x) {i=a; printf("Element x jest na %d miejscu\n", i+1); break;};	
	}
	if (i==-1) printf("Brak elementu x w tablicy\n");
	return 0;
}

