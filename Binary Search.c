#include<stdio.h>

int main ()
{
    int n,i,t;
    printf("Enter the length of your list: ");
    scanf("%d",&n);

    int ara[n];

    printf("Enter your list: ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    printf("Enter the number you want to search: ");

    scanf("%d",&t);

    int index=-1;

    int f=0,m;
    int l=n-1;

    while(f<=l)
    {
        m=(f+l)/2;

        if(ara[m] == t)
        {
            index=m;
            break;
        }
        else if(t>ara[m]) f=m+1;
        else l=m-1;
    }

    if(index==-1) printf("%d is not found in your list.",t);
    else printf("%d is found in the %dth position in your list.",t,(index+1));
    printf("\n\n\n\n\n\n");

    return 0;
}
