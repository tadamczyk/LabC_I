#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int Random=rand()%25+1;
    int n;
    printf("--------- GRA ----------\n");
    printf("Podaj liczbe od 1 do 25: ");
    while(n!=Random)
    {
        scanf("%d", &n);
        if(n>Random) printf("Podales za duza liczbe. Podaj kolejna: ");
        if(n<Random) printf("Podales za mala liczbe. Podaj kolejna: ");
    }
    printf("Brawo Ty! Odgadles liczbe numer %d!\n", Random);
    return 0;
}
