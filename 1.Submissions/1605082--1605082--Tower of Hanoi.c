#include<stdio.h>
int counter=1;

void Hanoi (n,s,h,d)
{
    if(n == 1)
    {
        printf("Move no.%d: %d to %d\n",counter,s,d);
        counter++;
    }
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

    printf("Here n stands for number of discs,\n");
    printf("s stands for the number denoted by source,\n");
    printf("h stands for the number denoted by helping column,\n");
    printf("and d stands for the number denoted by destination column.\n\n");
    printf("Enter the value of n,s,h,d respectively: ");
    scanf("%d %d %d %d",&n,&s,&h,&d);

    Hanoi(n,s,h,d);

    printf("\nTotal number of moves: %d\n\n",counter-1);

    return 0;
}
