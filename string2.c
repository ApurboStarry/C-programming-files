/*#include<stdio.h>

void strrev(char s[])
{
    int i,j ,temp;
    for(i=0,j=strlen(s)-1;i>strlen(s),j<=0;i++,j--)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
}

int main()
{
    char str[1000],str2[1000];

    gets(str);
    strrev(str);

    printf("%s", str);

    return 0;

}
*/

#include <stdio.h>


void strrev(char s[])
{
    int i, j;
    for (i = 0, j = strlen(s)-1; i<j; i++, j--)
    {
        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;

    }
}
main()
{
char s;
scanf("%c",&s);
printf("%c\n", s);
}
