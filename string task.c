#include<stdio.h>
#include<string.h>

int main()
{
    char ara[102];
    int l,i;

    scanf("%s",ara);

    l=strlen(ara);

    for(i=0;i<l;i++)
    {
        if(ara[i]!='a'&&ara[i]!='e'&&ara[i]!='i'&&ara[i]!='o'&&ara[i]!='u'&&ara[i]!='y'&&ara[i]!='A'&&ara[i]!='E'&&ara[i]!='I'&&ara[i]!='O'&&ara[i]!='U'&&ara[i]!='Y')
        {
            if(ara[i]>=66 && ara[i]<=90)
            {
                printf(".%c",(ara[i]-'A'+'a'));
            }
            else if(ara[i]>=98 && ara[i]<=122)
            {
                printf(".%c",ara[i]);
            }
        }
    }
    return 0;
}
