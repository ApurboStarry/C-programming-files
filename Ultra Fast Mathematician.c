#include<stdio.h>
#include<string.h>

int main()
{
    char ara1[102],ara2[102],sum[103];

    scanf("%s", ara1);
    scanf("%s", ara2);

    int i,j=0,l = strlen(ara1);
    for(i=0;i<l;i++)
    {
        sum[j] = ara1[i]^ara2[i];
        j++;
    }
    for(i=0;i<l;i++)
    {
        printf("%d",sum[i]);
    }

    return 0;
}
