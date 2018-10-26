#include<stdio.h>

int unimodal (int ara[],int l)
{
    int i,max = ara[0],inc  = 1,dec = 1,req,j,count;
    for(i = 0;i<l;i++)
    {
        if (ara[i] > max)
        {
            max = ara[i];
        }
    }
    for(i=0;i<l;i++)
    {
        if(ara[i] == max)
        {
            req = i,count = 0;
            for(j = i-1;j >= 0;j--)
            {
                if(ara[j] > max && ara[j] < ara[j-1])
                {
                    inc = 0;
                    break;
                }
                //if(count = req) inc = 1;
                //else inc = 0;
            }
        }
    }
    int countm = 0,constant =0;
    for(i=0;i<l;i++)
    {
        if(ara[i] == max) countm++;
    }
    for(i=req;i<(req+countm);i++)
    {
        if(ara[i] == max) constant = 1;
        else
        {
            constant =0;
            break;
        }
    }
    for(i = (req+countm);i<l;i++)
    {
        if(ara[i] <max && ara[i] > ara[i+1]) dec = 1;
        else
        {
            dec=0;
            break;
        }
    }
    if(dec == 1 && inc == 1 && constant == 1) return 1;
    else return 0;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int ara[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    int m;
    m = unimodal(ara,n);
    if(m == 1) printf("YES");
    else printf("NO");

    return 0;
}
