#include<stdio.h>

double pow(int x,int n)
{
    if (n == 1) return x;
    else return (x * pow(x,n-1));
}

int main()
{
    int x,n;
    printf("Determination of the value of x^n\n\n");
    printf("Enter the value of x: ");
    scanf("%d",&x);
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    printf("\nThe result %d^%d = %0.0lf\n",x,n,pow(x,n));

    return 0;
}
