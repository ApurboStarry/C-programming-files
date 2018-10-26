#include<stdio.h>

int main()
{
    int n,mx,mn,i;

    scanf("%d",&n);

    int ara[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    mx = 0;
    for(i=1;i<n;i++)
    {
        if(ara[i] > ara[mx]) mx = i;
    }

    mn = n-1;
    for(i=n-2;i>=0;i--)
    {
        if(ara[i] < ara[mn]) mn = i;
    }
    printf("\nmax = %d\tmin = %d\n",mx,mn);

    if(mx<mn)
    {
        int l = mx-0+n-1-mn;
        printf("%d",mx+n-1-mn);
    }
    else{
        int k = (mx-0) + (n-1-mn) - 1;
        printf("%d",k);
    }

    return 0;
}
