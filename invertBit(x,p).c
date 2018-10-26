/*Write down a function setBit(x,p) that will invert a bit
of integer x at position p leaving other bits unchanged.
Assume 0 <= p <=31*/


#include<stdio.h>

int invertBit(int x, int p)
{
    int m;
    m=1;
    m=m<<p;

    return (x^m);
}

int main()
{
    int x , p;
    printf("Enter the value of x & p respectively: ");

    scanf("%d %d",&x,&p);

    printf("The inputted number becomes %d",invertBit(x,p));

    return 0;
}
