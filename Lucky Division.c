#include<stdio.h>

int digit(int n)
{
    int count=0;
    while(n != 0)
    {
        n/=10;
        count++;
    }
    return count;
}

int main()
{
    int n,m;
    scanf("%d",&n);
    int dig;
    dig = digit(n);
    int flag = 0;
    if(dig == 1)
    {
        if((n%4) == 0) flag = 1;
        else if ((n%7) == 0) flag = 1;
        else flag = 0;
    }
    if(dig == 2)
    {
        if((n%47) == 0) flag = 1;
        else if ((n%74) == 0) flag = 1;
        else flag = 0;
    }

    if(flag == 1) printf("YES");
    else printf("NO");

    return 0;
}
