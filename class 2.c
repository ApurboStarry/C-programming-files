#include<stdio.h>

int gcd (int a,int b)
{
    int i,gcd,min;
    min=(a<b? a:b);
    for(i=1;i<=min;i++)
    {
        if(a%i==0&&b%i==0)
        {
            gcd=i;
        }
    }
    return gcd;
}

int main()
{
    int x,y,z,r;
    scanf("%d %d",&x,&y);
    r=gcd(x,y);
    r=gcd(r,z);

    printf("%d",r);

    return 0;
}
