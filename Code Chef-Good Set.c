#include<stdio.h>

int main()
{
    int ara[500];
    int i,j,k;
    for(i=0;i<500;i++)
    {
        ara[i] = 1;
    }
    ara[0] = 0;
    ara[1] = 1;
    ara[2] = 1;
    for(i=3;i<500;i++)
    {
        for(j=1;j<i;j++)
        {
            for(k=j+1;k<i;k++)
            {
                if(ara[k] == 1 && ara[j] == 1)
                {
                    if(j+k == i)
                    {
                        ara[i] = 0;
                    }
                }
            }
        }
    }

    /*
    int count = 0;
    for(i=0;i<500;i++)
    {
        if(ara[i] == 1)
        {
            printf("%d ",i);
            count++;
        }
    }
    printf("\nCount = %d",count-1);
    */

    int str[168];
    i=0;
    for(j=0;j<500;j++)
    {
        if(ara[j] == 1)
        {
            str[i] = j;
            i++;
        }
    }
    str[i] = '\0';

    /*
    for(i=0;i<168;i++)
    {
        printf("%d ",str[i]);
    }
    */

    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("%d ",str[i]);
        }
        printf("\n");
    }

    return 0;
}
