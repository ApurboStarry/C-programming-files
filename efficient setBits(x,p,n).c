/*Write down a function resetBits(x,p,n) that will reset the n
bits of the integer x starting from position p leaving other
bits unchanged. Assume 0 <= p <=31 and n <= p+1*/

//This is the efficient program of the previous one....
#include<stdio.h>

int main()
{
    int x,p,n,m;

    printf ("Enter the value of x ,p & n respectively: ");

    scanf("%d %d %d",&x,&p,&n);

    m=(~(~0<<n))<<(p-n+1);
    x=x|m;

    printf("After functioning, the number becomes: %d",x);

    return 0;
}
