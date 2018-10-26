#include<stdio.h>

int main()
{
    int a,b,c,i,ara[6],max;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    ara[0] = a + (b * c);
    ara[1] = a * (b + c);
    ara[2] = a * b * c;
    ara[3] = (a + b) * c;
    ara[4] = a + b + c;
    ara[5] = (a * b) + c;

    max = ara[0];
    for(i=1;i<6;i++)
    {
        if(ara[i] > max) max = ara[i];
    }

    printf("%d",max);

    return 0;
}
