#include<stdio.h>

int main()
{
    int ara[3],n,i,c=0;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d",&ara[0],&ara[1],&ara[2]);

        if((ara[0]+ara[1]+ara[2])>=2)
        {
            c++;
        }
    }
    printf("%d",c);

    return 0;
}
