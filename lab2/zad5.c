#include <stdio.h>
int main() 
{
	int a,b;
	printf("Podaj dwie liczby:\n");
	scanf("%d %d",&a,&b);
	while (a-b>=0)
	{
		a=a-b;
	};
	printf("Reszta z dzielenia a przez b wynosi %d\n",a);
	return 0;
}

