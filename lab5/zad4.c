#include <stdio.h>
int main()
{
	int i,n,w;
  	int tab[n+1];
  	printf("Podaj liczbe:\n");
  	scanf("%d",&n);
  	for(i=2;i<=n;i++) tab[i]=1;
  	for(i=2;i*i<=n;i++)
    		if(tab[i]==1)
    		{
     			w=i*i;
      			while(w<=n)
     			{
        			tab[w]=0;
        			w+=i;
      			}
		} 
  	for(i=2;i<=n;i++) 
  		if(tab[i]==1) printf("%d ",i);
  	printf("\n");
  	return 0;
}
