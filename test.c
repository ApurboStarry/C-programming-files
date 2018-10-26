#include<stdio.h>

int main()
{
    int n,x;

    scanf("%d %d",&n,&x);

    int ara[n];

    int i,idx,flag,diff;

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    for(i=0;i<n;i++)
    {
        diff = ara[i] - x;
        if(ara[i] == x)
        {
            printf("%d",i+1);
            return 0;
        }
        else if(ara[i] > x && diff == 1)
        {
            printf("%d",x-i);
            return 0;
        }
        else if (ara[i]>x && diff>1)
        {
            printf("%d",x+diff-1);
            return 0;
        }
    }
    if(i == n)
    {
        printf("0");
        return 0;
    }
    return 0;

}
