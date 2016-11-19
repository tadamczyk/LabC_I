#include <stdio.h>
int main() 
{
	int l,a,b,c;
	printf("Podaj liczbe calkowita:\n");
	scanf("%d",&l);
	for (a=1;a<=l-2;a++)
	{
		for (b=a+1;b<=l-1;b++)
		{
			for (c=b+1;c<=l;c++)
			{
				printf("{%d, %d, %d}\n",a,b,c);
			}
		}
	}
	return 0;
}
