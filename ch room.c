#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,l1,l2,count=0;
    char ara[105];
    char str[] = "hello";
    scanf("%s", ara);
    l1=strlen(ara);
    l2=strlen(str);
    for(i=0,j=0 ; i<l1,j<l2 ; i++,j++)
    {
        if(ara[i] == str[j])
        {
            count++;
        }
    }
    if(count == 5)
    {
        printf("YES");
    }
    else printf("NO");

    return 0;
}
