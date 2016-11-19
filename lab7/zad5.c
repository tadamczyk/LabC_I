#include <stdio.h>
#include <stdlib.h>
int sti(char str[])
{
    int n;
    n=atoi(str);
    //printf("Integer: %d\n", n);
    return n;
}
int main()
{
    char str[10];
    printf("Podaj liczbe string:\n");
    fgets(str,10,stdin);
    //sti(str);
    printf("Integer: %d\n", sti(str));
    return 0;
}
