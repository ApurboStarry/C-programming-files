#include<stdio.h>

int main()
{
    int n,i;

    printf("Enter the length of your list: ");

    scanf("%d",&n);

    int ara[n];

    printf("Enter your list: ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    int j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ara[i]>ara[j])
            {
                temp=ara[i];
                ara[i]=ara[j];
                ara[j]=temp;
            }
        }
    }

    printf("The ascending sorted list is: ");

    for(i=0;i<n;i++)
    {
        printf("%d ",ara[i]);
    }

    return 0;
}
