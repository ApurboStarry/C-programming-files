/*Write down a function invertBits(x,p,n) that will invert
n bits of the integer x starting from position p leaving
other bits unchanged. Assume 0 <= p <=31 and n <= p+1 */



#include<stdio.h>

int invertBit(int x, int p, int n)
{
    int m;
    m=(~(~0<<n))<<(p-n+1);
    return (x^m);
}

int main()
{

        int x, p, n;

        printf("Enter the value of x , p &n respectively: ");
        scanf("%d %d %d",&x,&p,&n);

        printf("The number becomes: %d",invertBit(x,p,n));

        return 0;

}
