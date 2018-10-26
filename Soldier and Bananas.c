#include<stdio.h>

int main()
{
    int k,n,w;
    scanf("%d %d %d",&k,&n,&w);
    int i, total = 0,req;
    for(i=1;i<=w;i++)
    {
        total = total + k*i;
    }
    req = total - n;
    if(req<0) printf("0");
    else printf("%d",req);

    return 0;
}
