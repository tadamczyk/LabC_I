#include <stdio.h>
int main()
{
	char c;
	printf("Podaj znak: ");
	scanf("%c",&c);
	if (c>=65 && c<=90) printf("Wpisales wielka litere\n");
	else if(c>=97 && c<=122) printf("Wpisales mala litere\n");
	else if (c>=48 && c<=57) printf("Wpisales cyfre\n");
	else printf("Wpisales inny znak\n");
	return 0;
}
