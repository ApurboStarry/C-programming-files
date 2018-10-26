#include<stdio.h>

int main()
{
    int mask,n;
    mask=1<<31;
    printf("Enter your number: ");

    scanf("%d",&n);

    if ((mask & n) == 0) printf("The number is positive\n");
    else printf("The number is negative\n");

    return 0;
}
