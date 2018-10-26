#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

void fibonacci(int n)
{
    int i,prev1,prev2,term;
    prev2=1;
    term=2;

    printf("1 2 ");

    for(i=3;i<=n;i++)
    {
        prev1=prev2;
        prev2=term;
        term=prev1+prev2;
        printf("%d ",term);
    }
    printf("\n");
}

void factorial(int n)
{
    int i,prd=1;
    for(i=1;i<=n;i++)
    {
        prd=prd*i;
    }

    printf("%d\n",prd);
}

void gotoxy(int x,int y)
{
    COORD c={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    system("cls");
    gotoxy(10,5);
    printf("fibnacci series upto %dth term: ",n);
    fibonacci(n);
    getche();//getche waits for inputting a character. When a character is inputted, the following statement is executed.
    system("cls");
    gotoxy(10,5);
    printf("The factoriaal of %d is : ",n);
    factorial(n);
    printf("\n\n\n\n\n\n");

    return 0;
}
