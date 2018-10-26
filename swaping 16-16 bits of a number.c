/*if you input 5;
5=0000....(24 times zero)....0101;
after functioning, num=0000 0000 0000 0101 0000..(12 times zero);
so, num=327680........*/


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
