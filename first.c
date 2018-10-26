#include<stdio.h>
#include<stdlib.h>

int main ()

{
    int count=0,n,i,j,k,l,min,d;
    long long int ara[10000000];
    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    min=abs(ara[0]-ara[1]);
    for(k=0;k<n;k++){
        for(l=k+1;l<n;l++)
        {
            d=abs(ara[k]-ara[l]);
            if(d<min)
            {
                min=d;
            }
            else if(d==min)
            {
                count++;
            }
        }
    }
    printf("%d %d",min,count);
    return 0;
}
