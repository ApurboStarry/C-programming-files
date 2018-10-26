#include<stdio.h>

int main ()
{
    int m=1,n;

    printf("Enter your number: ");

    scanf("%d",&n);

    if((m&n)==0) printf("The number is even");
    else printf("The number is odd");

    return 0;
}
