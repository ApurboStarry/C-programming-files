#include<stdio.h>
#include<string.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    int l = 2*n-1;
    char ara[l];
    memset(ara,0,sizeof(ara));

    scanf(" %[^\n]", ara);

    int n1 = 0,n2 = 0,n3 = 0,n4 = 0;

    for(i=0;i<l;i+=2)
    {
        if(ara[i] == '1') n1++;
        else if(ara[i] == '2') n2++;
        else if (ara[i] == '3') n3++;
        else if (ara[i] == '4') n4++;
    }

    int taxi = 0;

    if(n4 > 0) taxi += n4;
    if(n3>0) taxi += n3;
    if(n1>=n3) n1 -=n3;
    else if(n1<n3) n1 = 0;
    if((n1+n2*2) % 4 == 0) taxi +=(n1*1+n2*2)/4;
    else if((n1*1+n2*2) % 4 != 0)
    {
        taxi = taxi + (((n1*1+n2*2)/4) + 1);
    }

    printf("%d",taxi);

    return 0;
}
