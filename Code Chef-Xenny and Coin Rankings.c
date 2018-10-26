#include<stdio.h>

int main()
{
    int t,i;
    long long int u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&u,&v);
        long long int sum = 0;
        for(i=0;i<(u+v);i++)
        {
            sum = sum + i + 1;
        }
        sum = sum + u + 1;

        printf("%lld\n",sum);
    }
    return 0;
}
