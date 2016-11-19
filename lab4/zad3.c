#include <stdio.h>
int main()
{
	printf("Podaj liczbe calkowita:\n");
	int a,b,l;
	scanf("%d",&l);
	for (a=1;a<=l;a++)
	{
		for(b=1;b<=a;b++)
		{
			printf("*");
		}
		printf("\n");
	}
    return 0;
}
