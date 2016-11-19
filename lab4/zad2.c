#include <stdio.h>
int main()
{
	printf("Podaj dwie liczby calkowite:\n");
	int n,m;
	scanf("%d %d", &n, &m);
	int tab[n][m];
	int a,b;
	for (a=1;a<=n;a=a+1)
	{
		for (b=1;b<=m;b=b+1)
		{
			int x=a*b;
			tab[a][b]=x;
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}
