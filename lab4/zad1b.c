#include <stdio.h>
#include <string.h>
int main()
{
	printf("Podaj liczbe:\n");
        char liczba[32];
        fgets(liczba,32,stdin);
        int d=strlen(liczba),suma=0,a=0;
        for (;a<d;a++) suma=suma+liczba[a]-'0';
        printf("%d\n",suma+38);
        return 0;
}

