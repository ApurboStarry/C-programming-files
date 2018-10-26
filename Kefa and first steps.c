#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,count,j;
    char c[100000];

    scanf("%d",&n);

    int ara[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    j = 0;
    count = 1;

    for(i=0;i<n-1;i++)
    {
        if (i == n-2)
        {
            if(ara[i+1] >= ara[i])
            {
                count++;
                c[j] = count;
                j++;
            }
            else
            {
                c[j] = count;
                j++;
            }
        }
        else if(ara[i+1] >= ara[i])   count++;
        else if(ara[i+1] < ara[i])
        {
            c[j] = count;
            j++;
            count = 1;
        }
    }
    c[j] = '\0';

    //printf("%d",ara[n-1]);

    int k = strlen(c);
    int max = c[0];

    for(i=1;i<k;i++)
    {
        if(c[i] > max) max = c[i];
    }

    printf("%d",max);

    return 0;
}
