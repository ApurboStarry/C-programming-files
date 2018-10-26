#include<stdio.h>

int swapbits (int x)
{
    unsigned int y=x;

    return ((x<<16)|(y>>16));
}

int main()
{
    int x,b;
    scanf("%d",&x);
    b=swapbits(x);
    printf("%d",b);

    return 0;
}
