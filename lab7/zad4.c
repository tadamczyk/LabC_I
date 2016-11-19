#include <stdio.h>
char its(int n)
{
	char *wyn;
	char text[32];
	sprintf(text,"%d",n);
	wyn=text;
	printf("String: %s\n",wyn);
	//return *wyn;
}
int main()
{
	int n;
	printf("Podaj liczbe int:\n");
	scanf("%d",&n);
	its(n);
	//printf("String: %s\n",its(n));
	return 0;
}
