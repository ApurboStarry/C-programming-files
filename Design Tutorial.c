#include<stdio.h>
#include<math.h>

int prime(int p)
{
    int x = 1,i,root = sqrt(p);
    for(i=2;i<=root;i++)
    {
        if(p%i == 0)
        {
            x = 0;
            break;
        }
        else x = 1;
    }
    return x;
}

int main()
{
    int n,i;

    scanf("%d",&n);
    for(i=n-4;i>=4;i--)
    {
        if(prime(i)==0 && prime(n-i)==0)
        {
            printf("%d %d",i,n-i);
            break;
        }
    }

    return 0;
}
