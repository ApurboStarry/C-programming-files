#include<stdio.h>

int factorial ( int n)
{
    if (n == 0) return 1;
    return n*factorial(n-1);  //recursion is a special type of function that calls itself repeatedly....
}

int main()
{
    int n;

    printf("Enter the number: ");

    scanf("%d",&n);

    int f;
    f=factorial(n);
    printf("Factorial of %d is %d",n,f);

    return 0;
}
