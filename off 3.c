#include<stdio.h>
#include<stdlib.h>

char str1[10000],str2[1000],ch;


int strlen (char *str)
{
    int count=0;
    while(*str)
    {
        count++;
        str++;
    }

    return count;
}

int strcpy(char *str1,char *str2)
{
    int l=0;
    while(*str2)
    {
        *str1=*str2;
        str1++;
        str2++;
        l++;
    }
    *str1='\0';
    return l;
}

int lstrcat(char *str1, char *str2)
{
    int l=0;
    while(*str1)
    {
        str1++;
        l++;
    }

    while(*str2)
    {
        *str1=*str2;
        str1++;
        str2++;
    }
    *str1='\0';
    return l;
}

int strcmp( char *str1,char *str2)
{
   while(*str1!='\0' && *str2!='\0')
   {
       if(*str1<*str2) return -1;

       if(*str1>*str2) return 1;

       str1++;
       str2++;
   }
    if(strlen(str1) ==strlen(str2)) return 0;
    if(strlen(str1) < strlen(str2)) return -1;
    if(strlen(str1) > strlen(str2)) return 1;
}

void strlwr(char *str)
{
    while(*str)
    {
        if(*str>=65 && *str<=91) *str=*str+32;

        str++;
    }
    *str='\0';

}

void strupr(char *str)
{
    while(*str)
    {
        if(*str>=97 && *str<=122) *str=*str-32;

        str++;
    }
    *str='\0';

}

char* strstr(char *str, char *substr)
{
	  while (*str)
	  {
		    char *Begin = str;
		    char *pattern = substr;

		    while (*str && *pattern && *str == *pattern)
			{
			      str++;
			      pattern++;
		    }

		    if (!*pattern)
		    	  return Begin;

		    str=Begin+1;;
	  }
	  return NULL;
}


void strrev(char str[])
{
    int i, j;
    for (i = 0, j = strlen(str)-1; i<j; i++, j--)
    {
        int tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;

    }
}


char *strchr(const char *s, int c)
{
    while (*s != (char)c)
        if (!*s++)
            return 0;
    return (char *)s;
}


int main()
{
    int input;

    while(input!=11)
    {
        printf("\n Choose");
        printf("\n");
        printf("\n");
        printf("   1.For demonstrating strlen function\n");
        printf("   2.For demonstrating strcpy function\n");
        printf("   3.For demonstrating strcat function\n");
        printf("   4.For demonstrating strcmp function\n");
        printf("   5.For demonstrating strlwr function\n");
        printf("   6.For demonstrating strupr function\n");
        printf("   7.For demonstrating strchr function\n");
        printf("   8.For demonstrating strstr function\n");
        printf("   9.For demonstrating strrstr function\n");
        printf("   10.For demonstrating strrev function\n");
        printf("   11. For exit\n\n");


        printf("Enter your option: ");
        scanf("%d",&input);
        system("cls");
        switch(input)
        {
            case 1:
                    printf("Enter your string: ");
                    scanf(" %[^\n]", str1);

                    printf("\nThe length of your string is %d",strlen(str1));
                    getche();
                    system("cls");
                    break;

            case 2: printf("Enter the string to be copied: ");
                    scanf(" %[^\n]", str1);
                    char dest[100];
                    memset(dest,'\0',sizeof(dest));
                    strcpy(dest,str1);
                    printf("\nThe copied string is: %s",dest);
                    getche();
                    system("cls");
                    break;

            case 3: printf("Enter your first sting: ");
                    scanf(" %[^\n]", str1);
                    printf("\nEnter your second string that is to be concatenated: ");
                    scanf(" %[^\n]", str2);
                    strcat(str1,str2);
                    printf("After concatenation the strings become: %s",str1);
                    getche();
                    system("cls");
                    break;

            case 4: printf("Enter your first string: ");
                    scanf(" %[^\n]", str1);
                    printf("\nEnter your second string: ");
                    scanf(" %[^\n]", str2);
                    printf("%d",strcmp(str1,str2));
                    getche();
                    system("cls");
                    break;

            case 5: printf("Enter your string that is to be lowered: ");
                    scanf(" %[^\n]", str1);
                    strlwr(str1);
                    printf("The lowered string is: %s", str1);
                    getche();
                    system("cls");
                    break;

            case 6: printf("Enter your string that is to be uppered: ");
                    scanf(" %[^\n]", str1);
                    strupr(str1);
                    printf("The uppered string is: %s",str1);
                    getche();
                    system("cls");
                    break;

            case 7: printf("\t\t\tDemonstration of 'strchr' function\n");
                    printf("Enter a string: ");
                    scanf(" %[^\n]",str1);
                    printf("Enter a character: ");
                    scanf("%s",&ch);
                    char *p;
                    p=strchr(str1,ch);
                    printf("The result is: ");
                    printf(p);
                    getche();
                    system("cls");

            case 8: printf("\t\t\tDemonstration of 'strstr' function\n");
                    printf("Enter your string: ");
                    scanf(" %[^\n]", str1);
                    printf("Enter your second string: ");
                    scanf(" %[^\n]", str2);
                    p=strstr(str1,str2);
                    printf("The result is: ");
                    printf(p);
                    getche();
                    system("cls");
                    break;

            case 9: printf("\t\t\tDemonstration of strrstr\n");
                    printf("Enter your first string: ");
                    scanf(" %[^\n]", str1);
                    printf("Enter your second string: ");
                    scanf(" %[^\n]", str2);





            case 10: printf("Enter th estring that is to be reversed: ");
                     scanf(" %[^\n]", str1);
                     strrev(str1);
                     printf("The reversed string is: %s",str1);
                     getche();
                     system("cls");
                     break;

            case 11: printf("\t\t\tYou have successfully exited");
                     getche();
                     system("cls");
                     break;

            default: printf("Invalid input!!! Try again");
                     getche();
                     system("cls");
                     break;




        }
    }

    return 0;
}
