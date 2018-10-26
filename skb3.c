#include <stdio.h>
#include <string.h>

int main()
{
    char str[10000],str1[100],str2[100];
    printf("Enter your sentence: ");
    gets(str);
    printf("\nEnter the word which you want to replace: ");
    gets(str1);
    printf("\nEnter the word by which you want to replace: ");
    gets(str2);
    printf("\n");
    int len1=strlen(str1),len2=strlen(str2),l=strlen(str),n;
    int shift=len2-len1;

    //first implemented for right shift
    if(shift>=0)
    {
        while(strstr(str,str1)!=NULL)
        {
            char *old,*change,*new;
            old= strstr(str,str1);
            change = str+l;
            new=str2;

            n=len2;
            *(change+shift)='\0';
            change--;
            while(change!=old+len1-1)   //until we get str1
            {
                *(change+shift)=*change;  //right shifting
                change--;
            }
            while(n--)   //this loop will be executed len2 times and will replace str1 by str2
            {
                *old=*new;
                old++;
                new++;
            }
            l+=shift;   //declaring new length of str after shifting
        }
    }


    else      //i.e shift is negative
    {
        shift=-shift;
        while(strstr(str,str1)!=NULL)
        {
            char *old,*change,*new;
            old= strstr(str,str1);
            new=str2;
            while(*new)
            {
                *old=*new;
                old++;
                new++;
            }

            while(*(old+shift))         // 'shift' poriman ghor left shift korbe
            {
                *old=*(old+shift);
                old++;
            }
            *old='\0';
            l-=shift;
        }
    }

    printf("After replacing your sentence becomes: ");
    printf(str);

    return 0;
}
