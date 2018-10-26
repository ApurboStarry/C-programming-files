#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,x=0;
    char ara[4];

    scanf("%d",&n);
    while(n--)
    {
        gets(ara);

        if((int)strcmp(ara[4],"++X")==0 || (int)strcmp(ara[4],"X++")==0) x=x+1;
        else  x=x-1;
    }
    printf("%d",x);

    return 0;
}
