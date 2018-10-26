#include<stdio.h>

int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);    //a%b means a k b die vaag korle[a)b(..] ja vagshesh thake.
}

int main()
{
    int a,b,g;
    printf("Enter the first number: ");
    scanf("%d",&a);

    printf("Enter the second number: ");

    scanf("%d",&b);

    g=gcd(a,b);

    printf("The gcd of the given two number is %d",g);

    return 0;
}
