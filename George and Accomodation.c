#include<stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    int p[n],q[n];

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&p[i],&q[i]);
    }
    int count = 0;

    for(i=0;i<n;i++)
    {
        if(q[i] - p[i] >= 2) count++;
    }

    printf("%d",count);

    return 0;
}
