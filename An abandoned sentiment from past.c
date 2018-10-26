#include<stdio.h>

int *sort(int ara[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ara[j]>ara[i])
            {
                temp = ara[i];
                ara[i] = ara[j];
                ara[j] = temp;
            }
        }
    }
    return ara;
}

int main()
{
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    int ara1[n],ara2[k];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ara1[i]);
    }
    for(j=0;j<k;j++)
    {
        scanf("%d",&ara2[j]);
    }


    int *ara3 = sort(ara2,k);
    j = 0;

    for(i=0;i<n;i++)
    {
        if(ara1[i] == 0)
        {
            ara1[i] = ara3[j];
            j++;
        }
    }

    int flag = 0;
    for(i=0;i<n;i++)
    {
        if(ara1[i] > ara1[i+1])
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1) printf("Yes");
    else printf("No");


    return 0;
}
