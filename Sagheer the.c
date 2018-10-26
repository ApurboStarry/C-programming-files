#include<stdio.h>
#include<string.h>

int main()
{
    char ara [105];
    gets (ara);

    int nh=0,ne=0,nl=0,no=0,nr=0;
    int l=strlen (ara),i;

    for(i=0;i<l;i++)
    {
        if (ara[i] == 'h') nh++;
        else if (ara[i] == 'e') ne++;
        else if (ara[i] == 'l') nl++;
        else if (ara[i] == 'o') no++;
        else nr++;
    }

    int flag = 0;

    if(nh>1 || ne>1 || nl>2 || no>1 || nr>0) flag = 1;
    else flag = 0;

    if (flag == 1) printf("YES");
    else printf("NO");
}
