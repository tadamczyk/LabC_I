#include <stdio.h>
int main()
{
	int n,i=0;
	scanf("%d",&n);
	char bin[40];
	while(n!=0)
	{
		bin[i]=n%2;
		n=n/2;
		i++;
	}
	while(i>0)
	{
		i--;
		printf("%d",bin[i]);
	}
	printf("\n");
	return 0;
}	
