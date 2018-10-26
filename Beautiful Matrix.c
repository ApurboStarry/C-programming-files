#include<stdio.h>

int main()
{
    int i,j,k,l,ara[5][5],p,q;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&ara[i][j]);
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(ara[i][j] == 1)
            {
                p = i;
                q = j;
            }
        }
    }
    if(p>2) k = p-2;
    else k = 2-p;
    if(q>2) l = q-2;
    else l = 2-q;

    printf("%d",k+l);

    return 0;
}
