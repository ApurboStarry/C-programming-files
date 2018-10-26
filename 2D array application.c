#include<stdio.h>

int main()
{
    char ara[2][10];
    int i;
    for(i=0;i<2;i++)
    {
        scanf("%s",(*(ara+i)));
    }

    printf("%c",*(*(ara+1)+1));

    return 0;
}
