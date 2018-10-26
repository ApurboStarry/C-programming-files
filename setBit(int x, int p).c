/*Write down a function setBit(x,p) that will set a bit of
integer x at position p leaving other bits unchanged.
Assume 0 <= p <=31*/

#include<stdio.h>

int setBits(int x,int p)
{
    int m=1;
    m=m<<p;
    return (m|x);
}

int main()
{
    int x,p,n;

    printf("Enter the integer number: ");

    scanf("%d",&x);

    printf("Enter the position you want to set a bit: ");

    scanf("%d",&p);

    n=setBits(x,p);
    printf("After setting a bit into the %dth position of %d, the number becomes: %d\n\n",p,x,n);

    return 0;
}
