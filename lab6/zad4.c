#include <stdio.h>
int swap(int x, int y)
{
    x=x+y;
    y=x-y;
    x=x-y;
    printf("%d %d\n", x, y);
}
int main()
{
    int a,b;
    printf("Podaj dwie liczby calkowite:\n");
    scanf("%d %d", &a, &b);
    swap(a,b);
    return 0;
}
