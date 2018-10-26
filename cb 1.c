#include<stdio.h>
#include<string.h>

int main()
{
    int n,l;
    char ara[100];

    scanf("%d",&n);

    while(n--)
    {
        scanf("%s",&ara);
        l=strlen(ara);

        if(l>=10)
        {
            printf("%c%d",ara[0],(l-2));
            printf("%c",ara[l-1]);
        }
        else printf("%s",ara);
        printf("\n");
    }
    return 0;
}
