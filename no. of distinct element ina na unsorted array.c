#include<stdio.h>


int main()
{
    int ara[5],n,t,i,j,counter;
    scanf(" %[^\n]", ara);
    n=5;
    counter=5;
    for(i=0;i<n-1;i++)
    {
        t=ara[i];
        for(j=i+1;j<n;j++)
        {
            if(t==ara[j])
            {
                counter--;
                break;

            }
        }
    }

    printf("%d",counter);

    return 0;
}
