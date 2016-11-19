#include <stdio.h>
int main()
{
        int n,i=0;
        scanf("%d",&n);
        char hex[40];
        while(n!=0)
        {
		int x=n%16;
		if (x<10) hex[i]='0'+x;
                if (x==10) hex[i]='A';
                if (x==11) hex[i]='B';
                if (x==12) hex[i]='C';
                if (x==13) hex[i]='D';
                if (x==14) hex[i]='E';
                if (x==15) hex[i]='F';
                n=n/16;
                i++;
        }
        while(i>0)
        {
                i--;
                printf("%c",hex[i]);
        }
        printf("\n");
        return 0;
}

