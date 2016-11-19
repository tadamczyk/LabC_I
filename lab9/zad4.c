#include <stdio.h>
#define MAXN 1000
int n,tab[MAXN];
int min(int z1, int z2)
{
    if (z1<z2) return z1;
    else return z2;
}
int roz(int tab[], int ti, int k, int m)
{
    int a;
    if (m==0)
    {
        for (a=1;a<ti;a++)
            printf("%d ",tab[a]);
        printf("%d\n",tab[ti]);
    }
    else
    {
        ti=ti+1;
        for (a=min(m,k);a>0;a--)
        {
            tab[ti]=a;
            roz(tab,ti,a,m-a);
        }
    }
}
int main()
{
    printf("Podaj liczbe int:\n");
    scanf("%d",&n);
    roz(tab,0,n,n);
    return 0;
}
