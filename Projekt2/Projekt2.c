/********************************
*       TOMASZ ADAMCZYK    	*
*       Nr albumu: 243217       *
*       Informatyka I ROK       *
*       Projekt2.c         	*
********************************/
#include <stdio.h>
/**********   MINIMUM   **********/
int min(int tab[], int n)
{
   int w=tab[0],i;
   for (i=0;i<n;i++)
      if (tab[i]<w) w=tab[i];
   return w;
}
/**********   MAXIMUM   **********/
int max(int tab[], int n)
{
   int w=tab[0],i;
   for (i=0;i<n;i++)
      if (tab[i]>w) w=tab[i];
   return w;
}
/**********   ŚREDNIA   **********/
double ave(int tab[], int n)
{
   double w=0;
   int i;
   for (i=0;i<n;i++)
      w+=tab[i];
   return w/n;
}
/**********   MEDIANA   **********/
double med(int tab[], int n)
{
   double w=0;
   int i,tmp[n]; //DODATKOWA TABLICA tmp[n], ABY ZACHOWAĆ TABLICE tab[n]
   for (i=0;i<n;i++) tmp[i]=tab[i];
   sort(tmp,n);
   if (n%2==0) w=(tmp[n/2-1]+tmp[n/2])/2.;
   if (n%2==1) w=tmp[n/2];
   return w;
}
/*********  WYSTĄPIENIA  *********/
int count(int tab[], int n)
{
   int i,b,w,tmp[n]; //DODATKOWA TABLICA tmp[n], ABY ZACHOWAĆ TABLICE tab[n]
   int MAX=max(tab,n);
   int tab_c[MAX];
   for (i=0;i<MAX;i++) tab_c[i]=0;
   for (i=0;i<n;i++) tmp[i]=tab[i];
   for (i=0;i<n;i++)
   {
      if (tab_c[i]==1) continue;
      w=0;
      for (b=i;b<n;b++)
      {
         if (tmp[b]==tmp[i]) {w++; tab_c[b]=1;};		
      }
      if (w==1) printf("%d:\t%d raz\n", tab[i], w);
      if (w>1) printf("%d:\t%d razy\n", tab[i], w);
   }
}
/**********  SORTOWANIE  *********/
int sort(int tab[], int n)
{
   int i,j,t;
   for (i=0;i<n;i++)
      for (j=0;j<n-i-1;j++)
         if (tab[j]>tab[j+1])
         {
            t=tab[j];
            tab[j]=tab[j+1];
            tab[j+1]=t;
         }
}
/**********    MAIN     **********/
int main()
{
   int a,n;
   printf("Podaj liczbe n:\n");
   scanf("%d",&n);
   while (n<=0)
   {
      printf("Podaj liczbe n>0:\n");
      scanf("%d",&n);
   }
   int tab[n];
   for (a=0;a<n;a++) scanf("%d",&tab[a]);
   printf("\n*******************************\n\n");
   printf("Minimum:\n%d\n", min(tab,n));
   printf("Maximum:\n%d\n", max(tab,n));
   printf("Srednia:\n%.2f\n", ave(tab,n));
   printf("Mediana:\n%.2f\n", med(tab,n));
   printf("Wystapienia liczb w tablicy:\n");
   count(tab,n);
   printf("Posortowana tablica:\n");
   sort(tab,n);
   for (a=0;a<n;a++) printf("%d\n", tab[a]);
   return 0;
}
