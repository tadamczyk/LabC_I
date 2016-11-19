#include <stdio.h>
int main()
{
	int a=999;
	while (a>99)
	{
		int s=a-a%100;
		int d=(a%100)/10;
		int j=a-s-(d*10);
		s=s/100;
		if (s>d && s>j && d>j) printf("%d\n",a);
		//printf("%d %d %d",s,d,j);
		a=a-1;
	}
}
