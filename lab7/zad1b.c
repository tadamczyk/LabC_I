#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int zamien(int *x, int *y)
{
    *x^=*y;
    *y^=*x;
    *x^=*y;
}
int main()
{
    srand(time(0));
    int n,a,b;
    printf("Podaj liczbe int:\n");
    scanf("%d", &n);
    int tab[n];
    for (a=0;a<n;a++) {tab[a]=rand()%2; printf("%d\n",tab[a]);};
    printf("-----\n");
    for (a=0;a<n;a++)
    {
	for (b=n-1;b>a;b--)
    	   if (tab[b]<tab[a]) zamien(&tab[a],&tab[b]);
    }
    for (a=0;a<n;a++) printf("%d\n",tab[a]);
    return 0;
}
