#include<stdio.h>
#include<string.h>

int main()
{
    int num,i = 0,n,j,ara[4];

    scanf("%d",&num);
    //printf("\n%d\n",num);

    //int count = 0;

    for(i=num+1;i<=9000;i++)
    {
        j = 0;
        n = i;
        while(n)
        {
            ara[j] = n % 10;
            j++;
            n = n / 10;
        }
        if(ara[0]!=ara[1] && ara[0]!=ara[2] && ara[0]!=ara[3] && ara[1]!=ara[2] && ara[1]!=ara[3] && ara[2]!=ara[3])
        {
            printf("%d",i);
            break;
        }
        //printf("\n%d\n%d %d %d %d\n",i,ara[0],ara[1],ara[2],ara[3]);
        //memset(ara,0,4);
        //count++;
        //if(count == 3) break;
    }

    return 0;
}
