#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sortowanie_babelkowe(int tab[],int n)
{
  int i,j,t;
  for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
        if(tab[j]>tab[j+1])
        {
            t=tab[j];
            tab[j]=tab[j+1];
            tab[j+1]=t;
        }
}
int main()
{
    srand(time(0));
    int n,a;
    printf("Podaj liczbe n:\n");
    scanf("%d",&n);
    int tab[n];
    for(a=0;a<n;a++)
        tab[a]=rand()%100+1;
    sortowanie_babelkowe(tab,n);
    for(a=0;a<n;a++)
          printf("%d\n", tab[a]);
    return 0;
}
