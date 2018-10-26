#include<stdio.h>

int main()
{
    int n,m,i;

    scanf("%d %d",&n,&m);

    if(n < m) i = n;
    else if(m < n) i = m;
    else i = m;

    if(i%2 == 0) printf("Malvika\n");
    else printf("Akshat\n");

    return 0;
}
