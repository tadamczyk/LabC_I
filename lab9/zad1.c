#include <stdio.h>
int licznik(int x)
{
    if(x>1) return 1+licznik(x/10);
}
int main()
{
    int n;
    printf("Podaj liczbe calkowita:\n");
    scanf("%d",&n);
    if (n==0) printf("Liczba sklada sie z 1 cyfr.\n");
    else printf("Liczba sklada sie z %d cyfr.\n", licznik(n));
    return 0;
}
