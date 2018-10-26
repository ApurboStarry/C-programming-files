#include<stdio.h>

int main()
{
    int n,p,q,i;

    scanf("%d",&n);

    int flag[n+1];

    for(i=0;i<n+1;i++)
    {
        flag[i] = 0;
    }

    scanf("%d",&p);

    int arap[p];

    for(i=0;i<p;i++)
    {
        scanf("%d",&arap[i]);
    }

    scanf("%d",&q);

    int araq[q];

    for(i=0;i<q;i++)
    {
        scanf("%d",&araq[i]);
    }
    /*
    printf("%d\n%d",n,p);
    for(i=0;i<p;i++)
    {
        printf("%d ",arap[i]);
    }
    printf("\n%d ",q);
    for(i=0;i<q;i++)
    {
        printf("%d ",araq[i]);
    }
    */
    for(i=0;i<p;i++)
    {
        flag[arap[i]] = 1;
    }
    for(i=0;i<q;i++)
    {
        flag[araq[i]] = 1;
    }

    int count = 0;
    for(i=1;i<n+1;i++)
    {
        if(flag[i] == 0) count++;
    }
    if(count > 0) printf("Oh, my keyboard!");
    else printf("I become the guy.");

    return 0;
}
