#include <stdio.h>
int licznik(int x)
{
	int l=0;
	while (x)
	{
		l++;
		x/=10;
	};
	return l;
}
int main()
{
	int n;
	printf("Podaj liczbe calkowita:\n");
	scanf("%d",&n);
	printf("Liczba sklada sie z %d cyfr\n", licznik(n));
	return 0;
}
