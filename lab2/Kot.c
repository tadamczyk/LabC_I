#include <stdio.h>
int main()
{
	int l;
	printf("Podaj liczbe: ");
	scanf("%d",&l);
	int l2=l;
	while (l>0)
	{
		printf("%d\n",l);
		l=l-1;
	}
	l=l+1;
	printf("Reverse: \n");
	while (l<=l2)
	{
		printf("%d\n",l);
		l=l+1;
	}
	return 0;
}

