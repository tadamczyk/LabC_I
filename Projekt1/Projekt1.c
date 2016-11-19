/********************************
*	TOMASZ ADAMCZYK		*
*	Nr albumu: 243217	*
*	Informatyka I ROK	*
*	Projekt1.c		*
********************************/
#include <stdio.h>
#include <ctype.h>
int main()
{
   int n,w=0;
   scanf("%d", &n);
   int n1=n;
   do
   {
   	   n1=getchar();
   	   if (isalpha(n1) || ispunct(n1)) w++;
   }
   while (n1!='\n');
   if (w!=0) {printf("Bledne dane wejsciowe!\n"); return 1;};
   if (n<0 || n>9999) {printf("Liczba spoza zakresu!\n"); return 1;};
   if (n==0) printf("zero");
   int t=n-(n%1000);
   switch(t)
   {
      case 1000: printf("tysiac "); break;
      case 2000: printf("dwa tysiace "); break;
      case 3000: printf("trzy tysiace "); break;
      case 4000: printf("cztery tysiace "); break;
      case 5000: printf("piec tysiecy "); break;
      case 6000: printf("szesc tysiecy "); break;
      case 7000: printf("siedem tysiecy "); break;
      case 8000: printf("osiem tysiecy "); break;
      case 9000: printf("dziewiec tysiecy "); break;
      default: break;
   }
   int s=n-t-(n%100);
   switch(s)
   {
      case 100: printf("sto "); break;
      case 200: printf("dwiescie "); break;
      case 300: printf("trzysta "); break;
      case 400: printf("czterysta "); break;
      case 500: printf("piecset "); break;
      case 600: printf("szescset "); break;
      case 700: printf("siedemset "); break;
      case 800: printf("osiemset "); break;
      case 900: printf("dziewiecset "); break;
      default: break;
   }
   int d=n-t-s-(n%10);
   if (d>19) switch(d)
   {
      case 20: printf("dwadziescia "); break;
      case 30: printf("trzydziesci "); break;
      case 40: printf("czterdziesci "); break;
      case 50: printf("piecdziesiat "); break;
      case 60: printf("szescdziesiat "); break;
      case 70: printf("siedemdziesiat "); break;
      case 80: printf("osiemdziesiat "); break;
      case 90: printf("dziewiecdziesiat "); break;
      default: break;
   }
   if (d<20 && d>9)
   {
      d=d+n%10;
      switch(d)
      {
   	 case 10: printf("dziesiec "); break;
   	 case 11: printf("jedenascie "); break;
   	 case 12: printf("dwanascie "); break;
   	 case 13: printf("trzynascie "); break;
   	 case 14: printf("czternascie "); break;
   	 case 15: printf("pietnascie "); break;
   	 case 16: printf("szesnascie "); break;
   	 case 17: printf("siedemnascie "); break;
   	 case 18: printf("osiemnascie "); break;
   	 case 19: printf("dziewietnascie "); break;
         default: break;
      }
   }
   int j=n-t-s-d;
   if (n<10) j=n;
   switch(j)
   {
      case 1: printf("jeden"); break;
      case 2: printf("dwa"); break;
      case 3: printf("trzy"); break;
      case 4: printf("cztery"); break;
      case 5: printf("piec"); break;
      case 6: printf("szesc"); break;
      case 7: printf("siedem"); break;
      case 8: printf("osiem"); break;
      case 9: printf("dziewiec"); break;
      default: break;
   }
   printf("\n");
   return 0;
}

