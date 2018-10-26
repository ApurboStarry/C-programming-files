#include<stdio.h>

int main()
{
    long long int n;
    scanf("%l64d",&n);

    int count = 0,mod;

    while(n != 0)
    {
        mod = n%10;
        n = n / 10;
        if(mod == 4 || mod == 7) count++;
    }

    if(count == 4 || count == 7) printf("YES");
    else printf("NO");

    return 0;
}
