#include <stdio.h>
int suma(int x)
{
    if(x>0) return x%10+suma(x/10);
    return 0;
}
int main()
{
    int n;
    printf("Podaj liczbe calkowita:\n");
    scanf("%d",&n);
    printf("Suma cyfr wynosi %d.\n", suma(n));
    return 0;
}
