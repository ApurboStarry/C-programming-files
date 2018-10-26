#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int flag = 0; //No
    if(n%4 == 0) flag = 1;  //;YES
    else if (n%7 == 0) flag = 1;
    else if (n%47 == 0) flag = 1;
    else if (n%74 == 0) flag = 1;
    else if (n%444 == 0) flag = 1;
    else if (n%447 == 0) flag = 1;
    else if (n%474 == 0) flag = 1;
    else if (n%477 == 0) flag = 1;
    else if (n%747 == 0) flag = 1;
    else if (n%774 == 0) flag = 1;
    else if (n%777 == 0) flag = 1;
    else if (n%744 == 0) flag = 1;
    else flag = 0;

    if (flag == 1) printf("YES");
    else printf("NO");

    return 0;
}
