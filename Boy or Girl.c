#include<stdio.h>
#include<string.h>

int main()
{
    char ara [150];

    gets(ara);

    int l = strlen(ara);
    int i,j,count = 0;

    for(i=0;i<l-1;i++)
    {
        for(j=i+1;j<l;j++)
        {
            if(ara[i] == ara[j])
            {
                count++;
                break;
            }
        }
    }

    int m = l - count;

    if(m%2 == 1) printf("IGNORE HIM!");
    else printf("CHAT WITH HER!");

    return 0;
}
