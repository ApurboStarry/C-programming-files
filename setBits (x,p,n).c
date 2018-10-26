/*Write down a function setBits(x,p,n) that will set the n
bits of the integer x starting from position p leaving
other bits unchanged. Assume 0 <= p <=31 and n <= p+1*/

#include<stdio.h>

int setBits(int x,int p)
{
    int m=1;
    m=m<<p;
    return (m|x);
}

int setBitsss(int x,int p ,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        x=setBits(x,p-i);
    }
    return x;
}

int main()
{
    int x,num ,p,n;
    printf("Enter the value of x,p &n respectively: ");

    scanf("%d %d %d",&x,&p,&n);
    num=setBitsss(x,p,n);

    printf("After functioning the number becomes: %d\n\n",num);

    return 0;
}
