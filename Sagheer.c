#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,ara[4][4];
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&ara[i][j]);
        }
    }

    int flag = 0;

    for(i=0;i<4;i++)
    {
        if (ara[i][3]==1)
        {
            for(j=0;j<3;j++)
            {
                if(ara[i][j]==1)
                {
                    flag = 1;
                    break;
                }
            }
            for(j=i+1,k=0;j<=4,k<3;j++,k++)
            {
                if(j == 4) j=0;
                if(ara[j][k] == 1)
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    if(flag == 1) printf("YES");
    else printf("NO");

    return 0;
}
