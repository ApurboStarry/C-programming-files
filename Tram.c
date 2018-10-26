#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int ara [n],i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum = sum+ara[i];
    }

    int amar[n],tar[n];
    amar[0] = 0;
    tar[0] = 0;

        for(i=0;i<n;i++)
        {
            amar[i+1] = amar[i]+ara[i];
            tar[i+1] = sum - ara[i]-tar[i];
            if (amar[i+1]>tar [i+1]) break;
        }


    printf("%d",i+1);

    return 0;
}
