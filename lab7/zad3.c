#include<stdio.h>
void wypisz(int tab[], int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d%c", tab[i], (i<n-1) ? ' ' : '\n');
}
void perm(int tab[], int n)
{
    int i,j,k;
    if (n<2) return;
    i=n-1;
    while ((i>0) && (tab[i-1]>=tab[i]))
        i--;
    if (i>0) 
    {
        j=n;
        while ((j>0) &&(tab[j-1]<=tab[i-1]))
            j--;
    }
    if ((i>0) && (j>0)) 
    {
        k=tab[i-1];
        tab[i-1]=tab[j-1];
        tab[j-1]=k;
    }
    for (i++, j=n; i<j;i++, j--) 
    {
        k=tab[i-1];
        tab[i-1]=tab[j-1];
        tab[j-1]=k;
    }
}
int main()
{
	int n,a;
	printf("Podaj liczbe n:\n");
	scanf("%d",&n);
	int tab[n],sil=1;
	for (a=0;a<n;a++) {tab[a]=a+1; sil=sil*(a+1);};
	wypisz(tab,n);
    	for (a=0;a<sil-1;a++) 
	{
        	perm(tab,n);
        	wypisz(tab,n);
    	}
    	return 0;
}
