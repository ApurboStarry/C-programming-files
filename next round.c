#include<stdio.h>
#include<string.h>

int main ()
{
    int n,k,c=0,z=0,i,l,j;

    scanf("%d %d",&n,&k);

    int ara[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    for(l=0;l<=k-1;l++)
    {
        if(ara[l]>0)
        {
            z++;
        }
    }
    for(j=k;j<n;j++)
    {
        if(ara[j]>0)
        {
            if(ara[j]==ara[k-1])
            {
                c++;
            }
        }
    }

    printf("%d",z+c);

    return 0;
}
