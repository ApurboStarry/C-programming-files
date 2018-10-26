#include<stdio.h>
#include<string.h>

int main()
{
    int n,t,i,j;
    scanf("%d %d",&n,&t);
    char ara[n];
    scanf("%s", ara);
    char temp;
    while(t--)
    {
        for(i=0;i<n;i++)
        {
            if(ara[i] == 'B' && ara[i+1] == 'G')
            {
                temp = ara[i];
                ara[i] = ara[i+1];
                ara[i+1] = temp;
                i = i + 1;
            }
        }
    }
    printf("%s",ara);
    return 0;

}

