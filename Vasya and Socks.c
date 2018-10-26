#include<stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,bought = 0;

    for(i=1;i*m<=n;i++)
    {
        bought++;
        if(bought%m == 0) bought++;
    }

    printf("%d",bought+n);

    return 0;
}
