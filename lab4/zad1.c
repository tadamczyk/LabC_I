#include <stdio.h>
#include <string.h>
int main() 
{
	char liczba[100];
	scanf("%s",&liczba);
	int d=strlen(liczba),suma=0,a=0;
	for (;a<d;a++) suma=suma+liczba[a]-'0';
	printf("%d",suma);
	return 0;
}
