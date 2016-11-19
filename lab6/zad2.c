#include <stdio.h>
int Pit(int a, int b, int c)
{
	int w=0;
	if (a>b && a>c) {int t=a;a=c;c=t;};
	if (b>a && b>c) {int t1=b;b=c;c=t1;};
	if (a*a+b*b==c*c) w=1;
	return w;
}
int main() 
{
	int n,i,j,k;
	printf("Podaj liczbe n:\n");
	scanf("%d",&n);
	for (i=1;i<=n-2;i++)
	{
		for (j=i+1;j<=n-1;j++)
		{
			for (k=j+1;k<=n;k++)
			if (Pit(i,j,k)) printf("%d %d %d\n", i,j,k);
		}
	}
	return 0;
}