#include<stdio.h>

void Hanoi (n,s,h,d)
{
    if(n == 1) printf("Move disc from %d to %d\n",s,d);
    else
    {
        Hanoi(n-1,s,d,h);
        Hanoi(1,s,h,d);
        Hanoi(n-1,h,s,d);
    }
}

int main()
{
    int n,s,h,d;
    /*Here n stands for number of discs,
    s stands for the number denoted by source,
    h stands for the number denoted by helping column,
    and d stands for the number denoted by destination column.*/
    printf("Enter the value of n,s,h,d respectively: ");
    scanf("%d %d %d %d",&n,&s,&h,&d);
    Hanoi(n,s,h,d);

    return 0;
}
