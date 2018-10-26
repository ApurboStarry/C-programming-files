//determination of factors like 54=2^1*3^3=2(1)3(3)
#include<stdio.h>
#include<math.h>

int is_factor(int n,int x)
{
    if(n%x==0) return 1;
    else return 0;
}

int is_prime(int x)
{
    int i;

    for(i=2;i<(x);i++)
    {
        if(x%i==0) break;
    }
    if(x==i) return 1;
    else return 0;
}

int how_many_times(int n,int x)
{
    int c=0;
    while(n%x==0)
    {
        n/=x;
        c++;
    }

    return c;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        if(is_factor(n,i)&&is_prime(i))
        {
            printf("%d(%d)",i,how_many_times(n,i));
        }

    }
    return 0;
}
