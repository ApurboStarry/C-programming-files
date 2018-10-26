#include<stdio.h>

int main()
{
    int n,i,j;

    scanf("%d",&n);

    int ara[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    for(j=1;j<=n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(ara[i] == j) printf("%d ",i+1);
        }
    }

    return 0;
}
