#include<stdio.h>
#include<math.h>
double ok=0.000001;
double sqr(double x)
{
    double a=1.,b=x;
    while(fabs(a-b)>ok)
    {
        a=(a+b)/2.;
        b=x/a;
    }
    return a;
}
int main()
{
    int x;
    printf("Podaj liczbe, z ktorej chcesz wyznaczyc pierwiastek:\n");
    scanf("%d",&x);
    int x1=x;
    printf("Pierwiastek z %d wynosi %.2f\n",x1,sqr(x));
    return 0;
}
