#include<stdio.h>

double power(double x,int n)
{
    if(n<0) return (1/power(x,-n));
    if(n == 0) return 1;
    if(n%2 == 1) return (x * power(x,n-1));
    double k = power(x,n/2);
    return k * k;
}

int main()
{
    int n;
    double x;
    printf("Determination of the value of x^n\n\n");
    printf("Enter the value of x: ");
    scanf("%lf",&x);
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    printf("\nThe result %lf^%d = %lf\n",x,n,power(x,n));

    return 0;
}
