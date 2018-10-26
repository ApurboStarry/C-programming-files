#include<stdio.h>

int main()
{
    long int x[10]={10,11,12,13,14,15,16,17,18,19};
    int i;

    for(i=0;i<10;i++)
    {
        printf("\ni=%ld   x[i]=%ld    *(x+i)=%ld",i,x[i],*(x+i));
        printf("\t&x[i]=%X   (x+i)=%X",&x[i],(x+i));
    }

    return 0;
}
