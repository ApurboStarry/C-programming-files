/*Write down a function resetBit(x,p) that will reset a bit
of integer x at position p leaving other bits unchanged.
Assume 0 <= p <=31*/


#include<stdio.h>

int resetBit(int x, int p)
{
    int m;
    m=1;
    m=m<<p;
    m=~m;

    return (x&m);
}

int main()
{
    int x,p;

    printf("Enter the value of x & p respectively: ");

    scanf("%d %d",&x,&p);

    printf("The number becomes %d",resetBit(x,p));

    return 0;
}
