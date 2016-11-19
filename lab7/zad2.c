#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void cykl_prawo(int *tab, int n, int k) 
{ 
   	int buf,i,j; 
   	for (i=0;i<k;i++) 
   	{	 
      		buf=*(tab+n-1); //buf=tab[n-1]; 
      		for(j=n-1;j>0;j--) 
           		*(tab+j)=*(tab+j-1); //tab[j]=tab[j-1];
      		*tab=buf; //tab[0]=buf;
	} 
} 
int main() 
{
	srand(time(0));
	printf("Podaj liczbe n i k:\n");
	int n,k,a;
	scanf("%d %d",&n, &k);
	int tab[n];
	for (a=0;a<n;a++)
	{
		tab[a]=rand()%100;
		printf("%d ",tab[a]);
	}
	printf("\n----------\n");
	cykl_prawo(tab,n,k);
	for (a=0;a<n;a++) printf("%d ",tab[a]);
	printf("\n");
	return 0;
}
