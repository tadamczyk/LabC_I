#include <stdio.h>
int main()
{
	int x,y;
	printf("Podaj x i y:\n");
	scanf("%d %d",&x,&y);
	if (x>=-10 && x<=10 && y>=-10 && y<=10) printf("TAK\n");
	else printf("NIE\n");
	return 0;
}
