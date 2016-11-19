#include <stdio.h>
int main()
{
	int k,dec=0,x=0;
	scanf ("%d",&k);
	while (k>0)
	{
		int oct;
		scanf("%d",&oct);
		dec=dec*8+oct;
		k=k-1;
	}
	printf("%d\n",dec);
	return 0;
}
