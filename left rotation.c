#include<stdio.h>

int main()
{
    int n,i;

    scanf("%d",&n);

    int ara[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    for(i=0;i<n-1;i++)
    {
        ara[i]=ara[i+1];
    }

    for(i=0;i<n-1;i++)
    {
        printf("%d ",ara[i]);
    }

    return 0;
}
