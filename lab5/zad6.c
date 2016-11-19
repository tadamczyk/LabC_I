#include <stdio.h>
int main()
{
        printf("Podaj liczbe elementow tablicy:\n");
        int n,a,w=0,s=0,i=-1;
        scanf("%d",&n);
        int tab[n];
        for (a=0;a<n;a++)
        {
                scanf("%d", &tab[a]);
		while (tab[a]<tab[a-1]) {printf("Podaj liczbe WIEKSZA od poprzedniej\n"); scanf("%d",&tab[a]);};
        }
 	int x;
        printf("Podaj liczbe x:\n");
        scanf("%d",&x);
        for (a=0;a<n;a++)
        {
            int l=0,p=n-1,sr;
            while (l<=p && s==0)
            {
                sr=(l+p)/2;
                if (tab[sr]==x) {printf("x jest w tablicy na miejscu %d\n", sr+1); s=1;  break;};
                if (tab[sr]>x) p=sr-1;
                else l=sr+1;
            }
        }
        if (s==0) printf("x nie ma w tablicy!\n");
        return 0;
}

